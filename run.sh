mkdir -p isodir/boot/grub
cp grub.cfg isodir/boot/grub/grub.cfg
cp build/kernel.bin isodir/boot/kernel.bin
grub-mkrescue -o kernel.iso isodir
qemu-system-i386 -cdrom kernel.iso

