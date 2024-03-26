home-made-serial README

HMS: `home-make-serial` serial implements for some kernels

### Prerequisites

- `aarch64-linux-gnu-` toolchain must be installed on the system.
- Ensure the necessary directories and paths are correctly set in the Makefile:
  - `SRC_DIR`: Source code directory.
  - `BUILD_DIR`: Directory for storing build artifacts.
  - `GEM5_PATH`: Path to the Gem5 simulator.

### Makefile Targets

- **`clean`**: Remove the `build` directory.
- **`pre_build`**: Create the `build` directory if it does not exist.
- **`all`**: Build all assembly files from the C source files.

### Customization

- Adjust the `CFLAGS` variable for compiler flags.
- Modify `LDFLAGS` for linker flags.
- Uncomment and configure additional flags as needed for your project.

### Usage

1. Ensure the `aarch64-linux-gnu-` toolchain is set up.
2. Update the paths and flags in the Makefile to match your project requirements.
3. Run `make clean` to remove previous build artifacts.
4. Execute `make all` to compile the C source files and generate assembly files.

### Note

- This Makefile is tailored for cross-compiling C code for ARM architecture using the `aarch64-linux-gnu-` toolchain.
- Make sure to review and adjust the compiler and linker flags based on your project specifications.

For any further assistance or inquiries, feel free to reach out.

 Breadth-First Search (BFS) - direction optimizing

```
$ bfs.elf 1 矩阵路径/名称

1/0 表示是否需要会进行多次迭代，迭代次数为 kernel_iter_times

 Example : ./bfs.elf 1 matrices/simple_test_csr.mtx
```矩阵下载：http://suitesparse.com

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
