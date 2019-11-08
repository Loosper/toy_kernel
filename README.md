# Toy kernel
This is a kernel I am developing as a toy. Its primary purpose is to teach me OS-s and proper usage of the C language.

## C language lessons
1. Macros that take parameters and do arithmetic with them should put parameters in brackets. Eg.: omitting the brackets around `par` in `#define MACRO(par) ((par) * 3)` will behave unexpectedly when par is equal to `a + 1`
1. (apparently) Bit-fields are very pretty but they are non-portable. Reason is that they are implementation-defined and Endianness/LSB/MSB are inconsistent between architectures (this will probably never go on another arch, but still).

## Resources
1. [osdev wiki](https://wiki.osdev.org)
1. [simple OS in rust](https://os.phil-opp.com/)
1. [multiboot spec](https://www.gnu.org/software/grub/manual/multiboot/multiboot.html)
1. [stddef definitions](https://pubs.open   group.org/onlinepubs/7908799/xsh/stddef.h.html)
1. [type punning](https://www.cocoawithlove.com/2008/04/using-pointers-to-recast-in-c-is-bad.html)
