//
// Created by Robert Starosta on 16/11/2026.
//

#include "proto_shell.h"

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

int proto_shell_init(void) {
    char line[PROTO_SHELL_ARG_MAX];
    size_t len = 0;

    uart_puts("> ");

    while (len < PROTO_SHELL_ARG_MAX - 1) {
        char c = uart_getc();
        if (c == 0x0A || c == 0x0D) break;
        line[len++] = c;
    }
    line[len] = '\0';

    const int status_of = proto_shell_exec(line);

    if (status_of == 1) {
        return 1;
    } else {
        return 0;
    }
}

int proto_shell_exec(char *line) {
    char *cmd = line;
    char *arg = "";

    char *space = str_find(line, ' ');
    if (space) {
        *space = '\0';
        arg = space + 1;
    }

    int return_code = 0;

    if (str_eq(cmd, "echo")) {
        proto_shell_echo(arg);
        return_code = 0;
    } else if (str_eq(cmd, "help")) {
        proto_shell_help();
        return_code = 0;
    } else if (str_eq(cmd, "stop")) {
        proto_shell_stop();
        return_code = 1;
    } else if (*cmd != '\0') {
        uart_puts("No command found\n");
        return_code = 0;
    }

    return return_code;
}

static void proto_shell_help(void) {
    uart_puts("This is simple help message.\n"
              "Currently available commands:\n"
              "- echo <text> - return your text\n"
              "- help - display this message\n"
              "- stop - stop the shell\n");
}

static void proto_shell_echo(const char *word) {
    uart_puts(word);
    uart_puts("\n");
}

static void proto_shell_stop(void) {
    uart_puts("Stopping the shell...\n");
}