#ifndef _STDLIB
#define _STDLIB

#include <stddef.h>


size_t strlen(char *str);
void *memcpy(void *dest, void *src, size_t len);
void *memset(void *s, int c, size_t n);
char *itoa(int value, char *str);
char *btoa(uint8_t byte, char *str);

#endif
