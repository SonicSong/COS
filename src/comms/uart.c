//
// Created by raven on 11/15/26.
//
#include "uart.h"

void delay(unsigned n) {
    while (n--) __asm__ volatile("nop");
}

void uart_init(void) {
    UART0_CR = 0;

    // GPIO14/15 -> ALT0 (TXD0/RXD0)
    uint32_t r = GPFSEL1;
    r &= ~((7u << 12) | (7u << 15));
    r |=  ((4u << 12) | (4u << 15));
    GPFSEL1 = r;

    // Disable pull-up/down on pins 14, 15
    GPPUD = 0;       delay(150);
    GPPUDCLK0 = (1u << 14) | (1u << 15);
    delay(150);
    GPPUDCLK0 = 0;

    UART0_ICR  = 0x7FF;
    UART0_IBRD = 0x1A;                 // 48 MHz UART clock -> 115200 baud
    UART0_FBRD = 3;
    UART0_LCRH = (3u << 5);          // 8N1, FIFO off
    UART0_IMSC = 0;
    UART0_CR   = (1u << 0) | (1u << 8) | (1u << 9);  // UARTEN, TXE, RXE
}

void uart_putc(char c) {
    while (UART0_FR & (1u << 5)) {}  // TXFF
    UART0_DR = (uint32_t)c;
}

void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}

char uart_getc(void) {
    while (UART0_FR & (1u << 4)) {}
    char enter = UART0_DR;
    if (enter == 0x0A || enter == 0x0D) {
        uart_puts("\r\n");
    } else {
        uart_putc(enter);
    }

    return enter;
}