#include <stddef.h>
#include <stdint.h>

#include "stdlib.h"


size_t strlen(char *str) {
    size_t i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void *memcpy(void *dest, void *src, size_t len) {
    for (size_t i = 0; i < len; i++) {
        ((uint8_t *) dest)[i] = ((uint8_t *) src)[i];
    }
    return dest;
}

void *memset(void *s, int c, size_t n) {
    for (size_t i = 0; i < n; i++) {
        ((uint8_t *)s)[i] = c;
    }

    return s;
}
