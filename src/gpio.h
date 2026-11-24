//
// Created by raven on 11/15/26.
//

#ifndef COS_BCM2710_H
#define COS_BCM2710_H

/// Base address of the peripheral base registers for BCM2710A1
#define PERIPH_BASE 0x3F000000UL

/// Base address of the local base registers for BCM2710A1
#define LOCAL_BASE  0x40000000UL

#define ARM_IRQ_BASE (PERIPH_BASE + 0xB000)
#define UART0_BASE  (PERIPH_BASE + 0x201000)

#endif //COS_BCM2710_H
