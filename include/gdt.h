#ifndef _GDT
#define _GDT
// this header defines structures for the Global Descriptor Table.
// The GDT contains these entries:
//  * a null descriptor
//  * segment descriptors - describe the same memory area, because we use
//    a flat model.
//    TODO: what will happen if we didn't?
//  * Tss (whatever that is)
//  * stuff I have yet to put in

#include <stdint.h>

#define GDT_SIZE 4

// A GTD entry is 8 bytes and has these fields:
//  * limit: 20 bits. Depending on granularity flag can describe bytes or
//    4KB chunks.
//  * base: 32 bits. Address where the segment begins
//  * type: 12 bits. Includes an access byte and some flags
// see https://wiki.osdev.org/GDT for details
// 3.4.5 Vol. 3A intel
struct __attribute__((__packed__)) segment_descriptor_t {
    uint16_t limit_0_15;
    uint16_t base_0_15;
    uint8_t base_16_23;
    uint8_t access;
    uint8_t limit_16_19_flags;
    uint8_t base_24_31;

};

// the format of the GDT register (lgdt and sgdt instructions)
struct __attribute__((__packed__)) gdtr_t {
    // number of bytes of the table
    // (osdev says -1, but intel manual has no mention)
    uint16_t limit;
    // address of table
    void *base;
};


void gdt_init();

#endif
