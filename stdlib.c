#include <stddef.h>
#include <stdint.h>

#include "stdlib.h"


size_t strlen(char *str) {
    size_t i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

// TODO: figure out how to use these form libgcc
// otherwise optimise them
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

// TODO: this is temporary until sprintf. Reason: assumes enough space
// int to decimal string
// TODO: base?
char *itoa(int value, char *str) {
    int i = 0;
    for (; value > 0; value /= 10, i++) {
        str[i] = '0' + value % 10;
    }

    str[i] = '\0';
    // decrement i to leave the null byte in place
    i--;

    // invert the symbols, because they are backwards
    for (int j = 0; i != j; j++, i--) {
        int tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    return str;
}

// str should be at least 9 bytes long
// byte to string
char *btoa(uint8_t byte, char *str) {
    int i = 8;
    str[i] = '\0';
    // go to last byte
    i--;

    for (; i >= 0; i--) {
        // read least significant bit and move to the next one
        str[i] = (byte & 0x01) ? '1' : '0';
        byte >>= 1;
    }

    return str;
}
