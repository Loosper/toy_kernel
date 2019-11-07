#ifndef _VGA_MODE
#define _VGA_MODE

#include <stdint.h>


// hardware constants
#define ROWS 25
#define COLUMNS 80
#define BUFFER_ADDR (0xb8000)

// software definitions
#define FORGROUND 0xf
#define BACKGROUND 0x0

#define BLANK_CHAR 0x0020

// BEWARE this is an index to a 2-byte structure
#define VGA_INDEX(row, col) ((row) * COLUMNS + (col))

void write_str(char *);

#endif