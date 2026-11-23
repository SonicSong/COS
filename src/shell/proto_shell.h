//
// Created by Robert Starosta on 16/11/2026.
//

#ifndef COS_PROTO_SHELL_H
#define COS_PROTO_SHELL_H

#include "../comms/uart.h"

void proto_shell_init(void);
void proto_shell_exec(char *line);

//Libc replacement
static int str_eq(const char *a, const char *b);
static char *str_find(char *s, char c);

//Programs
static void proto_shell_help(void);
static void proto_shell_echo(const char *word);

#endif //COS_PROTO_SHELL_H
