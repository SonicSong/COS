//
// Created by Robert Starosta on 16/11/2026.
//

#include "proto_shell.h"
#include <stdint.h>

#define PROTO_SHELL_ARG_MAX 2048

void proto_shell_init(void) {
    char string_input[PROTO_SHELL_ARG_MAX];
    uart_puts("> ");
    for (int i = 0; i < PROTO_SHELL_ARG_MAX; i++) {
        string_input[i] = uart_getc();
        
    }
}