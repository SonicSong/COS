//
// Created by Robert Starosta on 16/11/2026.
//

#include "proto_shell.h"

#include <stddef.h>
#include <stdint.h>

#define PROTO_SHELL_ARG_MAX 2048

static int str_eq(const char *a, const char *b) {
    while (*a && *a == *b) { a++; b++; }
    return *a == *b;
}

static char *str_find(char *s, char c) {
    for (; *s; s++) {
        if (*s == c) return s;
    }
    return NULL;
}

void proto_shell_init(void) {
    char line[PROTO_SHELL_ARG_MAX];
    size_t len = 0;

    uart_puts("> ");

    while (len < PROTO_SHELL_ARG_MAX - 1) {
        char c = uart_getc();
        if (c == 0x0A || c == 0x0D) break;
        line[len++] = c;
    }
    line[len] = '\0';

    proto_shell_exec(line);
}

void proto_shell_exec(char *line) {
    char *cmd = line;
    char *arg = "";

    char *space = str_find(line, ' ');
    if (space) {
        *space = '\0';
        arg = space + 1;
    }

    if (str_eq(cmd, "echo")) {
        proto_shell_echo(arg);
    } else if (str_eq(cmd, "help")) {
        proto_shell_help();
    } else if (*cmd != '\0') {
        uart_puts("No command found\n");
    }
}

static void proto_shell_help(void) {
    uart_puts("This is simple help message.\n"
              "Currently available commands:\n"
              "- echo <text> - return your text\n"
              "- help - display this message\n");
}

static void proto_shell_echo(const char *word) {
    uart_puts(word);
    uart_puts("\n");
}