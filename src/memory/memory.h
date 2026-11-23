//
// Created by Robert Starosta on 17/11/2026.
//

#ifndef COS_MEMORY_H
#define COS_MEMORY_H
#include <stddef.h>

void memcpy(void *dest, const void *src, size_t n);
void memset(void *dest, int c, size_t n);
void memmove(void *dest, const void *src, size_t n);

#endif //COS_MEMORY_H
