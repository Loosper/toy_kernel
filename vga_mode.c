// #include <stdint.h>
#include <stddef.h>

#include "vga_mode.h"
#include "stdlib.h"


// TODO: why can't i make this a 2 dimensional array?
// TODO: volatile? and warnings
uint16_t *screen = (uint16_t *) BUFFER_ADDR;

uint8_t cur_row = 0;
uint8_t cur_col = 0;


void advance_rows() {
    cur_col = 0;

    if (cur_row == ROWS - 1) {
        // reset to last row
        // cur_row = ROWS - 1;

        for (int i = 0; i < ROWS - 1; i++) {
            void *src = screen + VGA_INDEX(i + 1, 0);
            void *dest = screen + VGA_INDEX(i, 0);
            memcpy(dest, src, COLUMNS * 2);
        }

        for (int i = 0; i < COLUMNS; i++) {
            screen[VGA_INDEX(ROWS - 1, i)] = BLANK_CHAR;
        }

    } else {
        cur_row++;
    }
}


void write_str(char * str) {
    // could also do str[i] != '\0'
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '\n') {
            advance_rows();
            continue;
        }

        screen[VGA_INDEX(cur_row, cur_col)] = (
            (((FORGROUND & 0x0f) | (BACKGROUND << 4 )) << 8 | str[i])
        );

        cur_col++;
        // go back to beginning of the line
        if (cur_col >= COLUMNS) {
            advance_rows();
        }
    }
}
