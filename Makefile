PREFIX = i686-elf-

CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)ld

# -freestanding means that there are only stdbool, stddef, stdint, float, iso646, limits, stdarg available
CFLAFS = -Wall -Wextra -pedantic -ffreestanding -O2
LDFLAGS = -nostdlib -lgcc -ffreestanding

kernel: kernel.o boot.o vga_mode.o stdlib.o
	$(CC) -T linker.ld -o kernel.bin $(LDFLAGS) $(CLFAGS) kernel.o boot.o vga_mode.o stdlib.o

# TODO: compile ever .c file with proper dependencies automatically.
# don't write each one explicitly
kernel.o: kernel.c
	$(CC) -c kernel.c -o kernel.o $(CFLAFS)
vga_mode.o: vga_mode.c
	$(CC) -c vga_mode.c -o vga_mode.o $(CFLAFS)
stdlib.o: stdlib.c
	$(CC) -c stdlib.c -o stdlib.o $(CFLAFS)

boot.o: boot.s

.PHONY: clean
clean:
	rm -f *.o kernel.bin
