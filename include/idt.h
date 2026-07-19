#ifndef IDT_H
#define IDT_H

#define IDT_ENTRIES          256
#define KERNEL_CODE_SELECTOR 0x08
#define IDT_FLAG_INT32       0x8e

struct IDTElement {
    unsigned short lower;
    unsigned short selector;
    unsigned char zero;
    unsigned char flags;
    unsigned short higher;
};

extern struct IDTElement _idt[IDT_ENTRIES];
extern unsigned int base, base12;
extern unsigned int isr1, isr12;
extern void LoadIDT();

void InitialiseIDT();

#endif
