#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include "mkl.h"
#include "mkl_spblas.h"

using namespace std;
using namespace chrono;

struct tr_matrix {
  csr_matrix mat;
  vector<int> spvv8_len;
  vector<vector<int>> tasks;
};

tr_matrix tr_reorder(csr_matrix &mat, vector<vector<int>> &tasks) {
  tr_matrix tr;

  for (vector<int> &task : tasks) {
    unordered_map<int, vector<int>> buckets;

    for (int r : task) {
      int rowlen = mat.rowe[r] - mat.rowb[r];
      buckets[rowlen].push_back(r);
    }

    vector<int> keys;
    for (auto kv : buckets) {
      keys.push_back(kv.first);
    }
    sort(keys.begin(), keys.end());

    vector<int> order;
    vector<int> remain;
    for (int k : keys) {
      vector<int> &samelen_task = buckets[k];
      int left = samelen_task.size() % 8;
      if (k > 32)
        left = samelen_task.size();
      int bulk = samelen_task.size() - left;
      order.insert(order.end(), samelen_task.begin(), samelen_task.begin() + bulk);
      remain.insert(remain.end(), samelen_task.begin() + bulk, samelen_task.end());
    }

    tr.spvv8_len.push_back(order.size());

    task.clear();
    task.insert(task.end(), order.begin(), order.end());
    task.insert(task.end(), remain.begin(), remain.end());
  }

  tr.mat = apply_order(mat, tasks);

  int size = tasks.size();
  for (int t = 0; t < size; t++) {
    int start = tr.mat.tstart[t];
    int tr_len = tr.spvv8_len[t];
    int p = 0, c = 0;
    for (p = start; c < tr_len; c += 8, p += 8) {
      int rowlen = tr.mat.rowe[p] - tr.mat.rowb[p];
      int base = tr.mat.rowb[p];
      vector<double> nnz;
      vector<int> col;
      nnz.insert(nnz.end(), tr.mat.nnz + base, tr.mat.nnz + base + rowlen * 8);
      col.insert(col.end(), tr.mat.col + base, tr.mat.col + base + rowlen * 8);
      for (int l = 0; l < rowlen; l++) {
        for (int r = 0; r < 8; r++) {
          tr.mat.nnz[base + l * 8 + r] = nnz[r * rowlen + l];
          tr.mat.col[base + l * 8 + r] = col[r * rowlen + l];
        }
      }
    }
  }

  tr.tasks = tasks;

  return tr;
}

bool is_banded(csr_matrix &mat, int band_size = -1) {
  if (band_size == -1)
    band_size = mat.cols / 64;
  int band_count = 0;
  bool banded = false;
  
  for (int r = 0; r < mat.rows; r++) {
    int rb = mat.rowb[r];
    int re = mat.rowe[r];
    for (int i = rb; i < re; i++) {
      int col = mat.col[i];
      if (abs(col - r) <= band_size)
        band_count++;
    }
  }

  if (double(band_count) / mat.m >= 0.3) {
    banded = true;
  }

  return banded;
}


tr_matrix process(csr_matrix &mat, int panel_num) {
  vector<vector<int>> tasks(panel_num);

  int pos = 0;
  int len = mat.m / panel_num;
  int limit = mat.rows - 7;
  int i;
  int count = 0;
  for (i = 0; i < limit; i += 8) {
    for (int j = 0; j < 8; j++) {
      int rowlen = mat.rowe[i + j] - mat.rowb[i + j];
      if (rowlen > 0) {
        tasks[pos].push_back(i + j);
        count += rowlen;
      }
    }

    if (count >= len) {
      if (pos + 1 < panel_num) {
        pos += 1;
        count = 0;
      }
    }
  }

  if (i < mat.rows) {
    for (; i < mat.rows; i++) {
      tasks[pos].push_back(i);
    }
  }

  tr_matrix ret = tr_reorder(mat, tasks);
  return ret;
}
