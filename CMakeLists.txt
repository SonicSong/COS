cmake_minimum_required(VERSION 4.3)
project(COS LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPU_FLAGS -mcpu=cortex-a53 -mgeneral-regs-only)

add_executable(kernel.elf src/boot.S src/main.c src/comms/uart.c src/comms/uart.h src/gpio.h
        src/comms/mailbox.c
        src/shell/proto_shell.c
        src/shell/proto_shell.h
        src/memory/memory.c
        src/memory/memory.h)

target_compile_options(kernel.elf PRIVATE
        ${CPU_FLAGS}
        -ffreestanding -fno-builtin -fno-stack-protector
        -ffunction-sections -fdata-sections
        -Wall -Wextra -O2 -g)

target_link_options(kernel.elf PRIVATE
        ${CPU_FLAGS}
        -nostdlib -nostartfiles -static
        -T ${CMAKE_SOURCE_DIR}/linker.ld
        -Wl,--gc-sections
        -Wl,-Map=${CMAKE_BINARY_DIR}/kernel.map)

set_target_properties(kernel.elf PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/linker.ld)

add_custom_command(TARGET kernel.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:kernel.elf> ${CMAKE_BINARY_DIR}/kernel8.img
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:kernel.elf>
        COMMENT "Creating kernel8.img")