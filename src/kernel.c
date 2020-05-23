#include "x86_instructions.h"
#include "gdt.h"


void main() {
    // disable hardware interrupts until we've finished all initialisation
    cli();

    gdt_init();

    while (1);
}
