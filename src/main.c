#include <stdint.h>
#include "gpio.h"
#include "comms/uart.h"

void main(void) {
    uart_init();
    uart_puts("Hello World.\n");
    uart_puts("Running off a custom OS on Pi Zero 2 W!\n");
    uart_puts("> ");
    while (1) {
        uart_getc();
    }
    for (;;) __asm__ volatile("wfe");
}