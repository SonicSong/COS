#include <stdint.h>
#include "gpio.h"
#include "comms/uart.h"
#include "shell/proto_shell.h"

void main(void) {
    uart_init();
    uart_puts("Hello World.\n");
    uart_puts("Running off a custom OS on Pi Zero 2 W!\n");
    while (1) {
        proto_shell_init();
    }
    for (;;) __asm__ volatile("wfe");
}