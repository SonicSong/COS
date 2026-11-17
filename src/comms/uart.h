//
// Created by raven on 11/15/26.
//

#ifndef COS_UART_H
#define COS_UART_H

#include <stdint.h>
#include "../gpio.h"

#define GPFSEL1     (*(volatile uint32_t *)(PERIPH_BASE + 0x200004))
#define GPPUD       (*(volatile uint32_t *)(PERIPH_BASE + 0x200094))
#define GPPUDCLK0   (*(volatile uint32_t *)(PERIPH_BASE + 0x200098))

#define UART0_DR    (*(volatile uint32_t *)(UART0_BASE + 0x00))
#define UART0_FR    (*(volatile uint32_t *)(UART0_BASE + 0x18))
#define UART0_IBRD  (*(volatile uint32_t *)(UART0_BASE + 0x24))
#define UART0_FBRD  (*(volatile uint32_t *)(UART0_BASE + 0x28))
#define UART0_LCRH  (*(volatile uint32_t *)(UART0_BASE + 0x2C))
#define UART0_CR    (*(volatile uint32_t *)(UART0_BASE + 0x30))
#define UART0_IFLS  (*(volatile uint32_t *)(UART0_BASE + 0x34))
#define UART0_IMSC  (*(volatile uint32_t *)(UART0_BASE + 0x38))
#define UART0_MIS   (*(volatile uint32_t *)(UART0_BASE + 0x40))
#define UART0_ICR   (*(volatile uint32_t *)(UART0_BASE + 0x44))
#define UART0_DMACR (*(volatile uint32_t *)(UART0_BASE + 0x48))
#define UART0_ITCR  (*(volatile uint32_t *)(UART0_BASE + 0x80))
#define UART0_ITIP  (*(volatile uint32_t *)(UART0_BASE + 0x84))
#define UART0_ITOP  (*(volatile uint32_t *)(UART0_BASE + 0x88))
#define UART0_TDR   (*(volatile uint32_t *)(UART0_BASE + 0x8C))

void delay(unsigned n);

void uart_init(void);

void uart_putc(char c);

void uart_puts(const char *s);

char uart_getc(void);

#endif //COS_UART_H
