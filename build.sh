#! /bin/bash
#
# Script to build RISC-V ISA simulator, proxy kernel, and GNU toolchain.
# Tools will be installed to $RISCV.
export RISCV=~/SUNFLOWER
. build.common

echo "Starting RISC-V Toolchain build process"

build_project riscv-openocd --prefix=$RISCV --enable-remote-bitbang --enable-jtag_vpi --disable-werror
build_project riscv-fesvr --prefix=$RISCV
build_project riscv-isa-sim --prefix=$RISCV --with-fesvr=$RISCV
build_project riscv-gnu-toolchain --prefix=$RISCV
CC= CXX= build_project riscv-pk --prefix=$RISCV --host=riscv64-unknown-elf
cd SUNFLOWER
echo -e "\nCompile project test files"
make
echo -e "\\nRISC-V Toolchain installation completed!"
