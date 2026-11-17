#include <stdint.h>
#include "gpio.h"
#include "comms/uart.h"

void main(void) {
    uart_init();
    uart_puts("Hello World.\n");
    uart_puts("Running off a custom OS on Pi Zero 2 W!\n");
    uart_puts("> ");
    while (1) {
        char test_ch = uart_getc();
        uart_putc(test_ch);
    }
    for (;;) __asm__ volatile("wfe");
}