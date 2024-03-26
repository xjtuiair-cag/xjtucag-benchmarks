`benchmarks` README

HMS: `benchmarks` serial implements for some kernels

### Prerequisites

Make sure you have the GCC compiler and its associated toolchain installed

### Makefile Targets

- **`clean`**: Remove the `build` directory.
- **`pre_build`**: Create the `build` directory if it does not exist.
- **`all`**: Build all assembly files from the C source files.

### Usage

2. Update the paths and flags in the Makefile to match your project requirements.
3. Run `make clean` to remove previous build artifacts.
4. Execute `make all` to compile the C source files and generate assembly files.

### Note

- Make sure to review and adjust the compiler and linker flags based on your project specifications.

For any further assistance or inquiries, feel free to reach out.

 Breadth-First Search (BFS) - direction optimizing

```
$ bfs.elf 1 矩阵路径/名称

1/0 表示是否需要会进行多次迭代，迭代次数为 kernel_iter_times

 Example : ./bfs_scr.elf 1 matrices/simple_test_csr.mtx
 
```

 Single-Source Shortest Paths (SSSP) - delta stepping

PageRank (PR) - iterative method in pull direction

Connected Components (CC) - Afforest & Shiloach-Vishkin

Betweenness Centrality (BC) - Brandes

Triangle Counting (TC) - Order invariant with possible relabelling

```
  $ TC.elf true/false 矩阵路径/名称
  true/false 表示是否需要预热cache，分支预测器
  Example : ./TC.elf true matrices/simple_test_csr.mtx./bin/tc.elf true matrices/simple_test_csr.mtx
（选择一个矩阵文件）
```

Sparse Matrix-Dense Vector Multiplication（SPMV）-

Sparse Matrix-Matrix Multiplicatio（SPMM）- 

Symmetric Gauss-Seidel（SYMGS）-