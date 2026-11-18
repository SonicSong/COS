//
// Created by raven on 11/15/26.
//

#include "mailbox.h"

volatile unsigned int __attribute__((aligned(16))) mailbox[32];