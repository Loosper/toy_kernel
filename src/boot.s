# multiboot constants
.set MAGIC, 0x1BADB002 # multiboot magic number
.set ALIGN,    1 << 0  # align on page boundry
.set MEMINFO,  1 << 1  # produce a memory map
.set FLAGS, ALIGN | MEMINFO
.set CHECKSUM, -(MAGIC + FLAGS)

# multiboot sector
.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM

# stack section
.section .bss
.align 16      # go to first multiple of 16
stack_bottom:  # stack grows down, so the smallest address is the limit
    .skip 8192 # leave space for 8Kb stack
stack_top:

# executable code
.section .text
.global _start
.type _start, @function
# ENTRY POINT
_start:
    # stack is undefined at boot
    mov $stack_top, %esp

    call main

	# if main exits, disable interrupts and infinitely halt in case of another wake up
    cli
_hlt:
    hlt
    jmp _hlt

# osdev says this will eventually be useful for debugging or call tracing
# .size _start, . - _start

