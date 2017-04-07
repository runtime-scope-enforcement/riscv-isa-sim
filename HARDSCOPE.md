Spike is extended by adding an SRS class as part of the MMU and adding an access check to the MMU.
The SRS size and frame size can be configured in file `riscv/srs.h` with macros `SRS_STACK_FRAMES` and `SRS_ENTRIES`.
Instructions can be found from `riscv/insns` and must also be configured in riscv.mk.in and encoding.h files.

Build instructions
------------------

1. Build and install Spike front-end server, riscv-fesvr. E.g. run the normal riscv-tools build scripts.
2. Create a build directory and use that as a working directory: `mkdir build;cd build`
3. Run configure script: `../configure --prefix=/path/to/install/dir --with-fesvr=/path/to/fesvr/install/destination --with-isa=rv32ima`
4. Build and install: `make -j$(nproc) && make install`

You can also build a version of Spike that supports the pulpino memory layout which should allow running same binaries on Spike and pulpino.
This can be done by providing `--enable-pulpino` flag to the configuration script.

Usage
-----

HardScope is enabled by default and yields a lot of additional output.
Spike loads ELF binaries that are built with RISC-V GCC toolchain.
Spike supports proxy kernel which allows using e.g. standard IO and other syscalls.
Bare metal binaries can be run with `spike <binary>`, to use proxy kernel, use command `spike pk <binary>`.

HardScope extension mode can be changed with `--xscen` switch. Wtih value 0, default blocking is used. Value 1, enabled the lax delegation mode. Value 2, allows scope violations and increases debug output excessively.

Known issues
------------

Cycle counting for new instructions are not calibrated.

All instructions increment the cycle counter by one instead of taking into account the cost of the instructions on realistic hardware.
