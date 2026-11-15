//
// Created by raven on 11/15/26.
//

#ifndef COS_BCM2710_H
#define COS_BCM2710_H

#define PERIPH_BASE 0x3F000000UL
#define LOCAL_BASE  0x40000000UL

#define ARM_IRQ_BASE (PERIPH_BASE + 0xB000)
#define UART0_BASE  (PERIPH_BASE + 0x201000)

#endif //COS_BCM2710_H
