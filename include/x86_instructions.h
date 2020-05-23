#ifndef _X86_INSTRUCTIONS
#define _X86_INSTRUCTIONS

struct gdtr_t;

void lgdt(void *ptr);
void sgdt(struct gdtr_t *gdtr);
void cli();
void sti();

#endif
