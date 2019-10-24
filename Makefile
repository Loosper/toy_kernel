PREFIX = i686-elf-

CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)ld

# -freestanding means that there are only stdbool, stddef, stdint, float, iso646, limits, stdarg available
CFLAFS = -Wall -Wextra -pedantic -ffreestanding -O2
LDFLAGS = -nostdlib -lgcc

kernel: kernel.o boot.o
	$(CC) -T linker.ld -o kernel.bin $(LDFLAGS) $(CLFAGS) kernel.o boot.o

kernel.o: kernel.c
boot.o: boot.s

.PHONY: clean
clean:
	rm -f kernel.o boot.o kernel.bin

