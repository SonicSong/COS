# COS

Simple Operating System written in C to run on ARM devices such as Raspberry Pi, Orange Pi, etc.  
Now mainly tested in QEMU with target to run on Raspberry Pi Zero 2W.

Moved it from Rust [SonicSong/r_OS](https://github.com/SonicSong/r_os/) to C because of how toolchain did behave.

## Building
Setup in CLion toolchain with the following settings:
- C Compiler: `<dir_to_toolchain>/arm-gnu-toolchain-15.3.rel2-x86_64-aarch64-none-elf/bin/aarch64-none-elf-gcc`
- C++ Compiler: `<dir_to_toolchain>/arm-gnu-toolchain-15.3.rel2-x86_64-aarch64-none-elf/bin/aarch64-none-elf-g++`

Setup in CLion CMake with the following settings:
- CMake options: `-DCMAKE_TOOLCHAIN_FILE=$ProjectFileDir$/aarch64-toolchain.cmake`
- Build options: `-DCMAKE_BUILD_TYPE=Debug`
- Toolchain the one you did set up in the previous step.

## Testing with QEMU
To test the code with QEMU, you can use the following command:
- `qemu-system-aarch64 -M raspi3b -kernel cmake-build-debug-aarch64/kernel8.img -serial stdio -display none`