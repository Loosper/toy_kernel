#ifndef _VGA_MODE
#define _VGA_MODE

#include <stdint.h>

// the vga buffer is a linear array of memory. Every entry is a two byte field:
// lower byte: the colour
// upper byte: the character
// the colour is split in two: first 4 bits are the background and the upper 4
// are the foreground colour
// (see https://wiki.osdev.org/Text_UI)

// hardware constants
#define ROWS 25
#define COLUMNS 80
#define BUFFER_ADDR (0xb8000)

enum colours {
    black = 0x0,
    blue,
    green,
    cyan,
    red,
    magenta,
    brown,
    light_gray,
    // the following have the 'light' bit set,
    dark_gray,
    light_blue,
    light_green,
    light_cyan,
    light_red,
    light_magenta,
    yellow,
    white
};

// software constants
#define BLANK_CHAR 0x0020
#define GL_FG white
#define GL_BG black

// helper macros
#define COLOUR(fg, bg) ((bg) << 4 | (fg & 0x0f))
#define COLOURED_CHAR(fg, bg, chr) ((COLOUR(fg, bg)) << 8 | (chr))
// BEWARE this is an index to a 2-byte structure
#define VGA_INDEX(row, col) ((row) * COLUMNS + (col))

void write_str(char *);
void clear_screen();

#endif
