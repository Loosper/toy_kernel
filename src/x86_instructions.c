#include "x86_instructions.h"

// people do
// #define asmv __asm__ __volatile__


// store pointer to gdt register
void lgdt(void *ptr) {
    __asm__ volatile("lgdt (%0)" : : "r"(ptr));
}

// TODO: convert this to gdtr_t?
// retrieve gdt register
void sgdt(struct gdtr_t *gdtr) {
    __asm__ volatile("sgdt (%0)" : "=r"(gdtr));
}

// disable (hardware) interrupts
void cli() {
    __asm__("cli");
}

// enable (hardware) interrupts
void sti() {
    __asm__("sti");
}
