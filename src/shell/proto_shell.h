//
// Created by Robert Starosta on 16/11/2026.
//

#ifndef COS_PROTO_SHELL_H
#define COS_PROTO_SHELL_H

#include "../comms/uart.h"

#include <stddef.h>
#include <stdint.h>


int proto_shell_init(void);
int proto_shell_exec(char *line);

///Libc replacement.
/// Check whether the two strings are equal
static int str_eq(const char *a, const char *b);

///Libc replacement.
/// Find the first occurrence of a character in a string
static char *str_find(char *s, char c);

//Programs
static void proto_shell_help(void);
static void proto_shell_echo(const char *word);
static void proto_shell_stop(void);

#endif //COS_PROTO_SHELL_H
