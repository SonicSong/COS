//
// Created by raven on 11/15/26.
//

#include "mailbox.h"

// Mailboxes are 32bit
volatile unsigned int __attribute__((aligned(16))) mailbox[32];

// 16 mailboxes in total for 4 cores
// https://pip-assets.raspberrypi.com/categories/506-raspberry-pi-2-model-b/documents/RP-008250-DS-1-bcm2836-peripherals.pdf (#4 Registers) 