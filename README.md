# Toy kernel
This is a kernel I am developing as a toy

## C language lessons
1. Macros that take parameters and do arithmetic with them should put parameters in brackets. Eg.: omitting the brackets around `par` in `#define MACRO(par) ((par) * 3)` will behave unexpectedly when par is equal to `a + 1`