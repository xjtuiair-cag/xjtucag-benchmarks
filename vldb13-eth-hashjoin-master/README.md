# EFFICIENT MAIN-MEMORY HASH JOINS ON MULTI-CORE CPUS: TUNING TO THE UNDERLYING HARDWARE

[![Build](https://github.com/mars-research/vldb13-eth-hashjoin/actions/workflows/build.yml/badge.svg)](https://github.com/mars-research/vldb13-eth-hashjoin/actions/workflows/build.yml)

[![Docs](https://github.com/mars-research/vldb13-eth-hashjoin/actions/workflows/docs.yml/badge.svg)](https://github.com/mars-research/vldb13-eth-hashjoin/actions/workflows/docs.yml)

Change the join/hardware parameters at [src/prj_params.h](https://github.com/mars-research/vldb13-eth-hashjoin/blob/master/src/prj_params.h)

[Documentation](http://mars-research.github.io/vldb13-eth-hashjoin)

A fork of the ETH Zurich's VLDB'13 hashjoin obtained from [web archive](https://web.archive.org/web/20220414154544/https://systems.ethz.ch/research/data-processing-on-modern-hardware/projects/parallel-and-distributed-joins.html) (Under _Hash joins source code for the VLDB'13 paper_)

The original publication can be found at https://dl.acm.org/doi/abs/10.14778/2732219.2732227.

**WARNING**: run `enable_hugepages.sh` and `constant_frequency.sh` from kvstore repo before running your benchmarks!!!
