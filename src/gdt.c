#include <stdint.h>

#include "gdt.h"
#include "vga_mode.h"
#include "x86_instructions.h"


// right i won't bother with segmenting, so assume it's all 4KB pages
static struct segment_descriptor_t gdt_format_entry(uint32_t base, uint32_t limit, uint8_t access) {
    struct segment_descriptor_t entry;

    // provided is a 32 bit address. Convert to 20 bit address of 4KB pages
    // so just discard the 12 least significant bits, because we don't have the precision
    limit >>= 12;

    // if ((limit & 0xfff00000) != 0) {
    //     write_str("limit is a 20 bit value, but provided one was bigger");
    // }

    entry.base_0_15 = base & 0xffff;
    entry.base_16_23 = (base >> 16) & 0xff;
    entry.base_24_31 = (base >> 24) & 0xff;

    entry.limit_0_15 = limit & 0xffff;
    entry.limit_16_19_flags = (limit >> 16) & 0xf;

    // set granularity and size bits
    entry.limit_16_19_flags |= 0x11;

    entry.access = access;

    return entry;
}

static void *gdt_make() {
    static struct segment_descriptor_t gdt[GDT_SIZE];

    // null descriptor
    gdt[0] = gdt_format_entry(0, 0, 0);
    // code + data segments
    gdt[1] = gdt_format_entry(0, 0xffffffff, 0x9a);
    gdt[2] = gdt_format_entry(0, 0xffffffff, 0x92);
    // TODO: tss (task state segment) (osdev strongly recommends this one)
    // gdt[3] = gdt_format_entry(&Tss, sizeof(Tss), 0x89);

    return &gdt;
}

static void gdt_load(void *table, int size) {
    static struct gdtr_t descriptor;

    descriptor.limit = size * 8;
    descriptor.base = table;

    lgdt(&descriptor);
}

void gdt_init() {
    // cli();
    void *gdt = gdt_make();
    gdt_load(gdt, GDT_SIZE);

    write_str("gdt inited");
}
