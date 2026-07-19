#include "idt.h"
#include "pic.h"
#include "ports.h"

struct IDTElement _idt[IDT_ENTRIES];
unsigned int base, base12;

void InitialiseIDT() {
    _idt[1].lower = (base & 0xffff);
    _idt[1].higher = (base >> 16) & 0xffff;
    _idt[1].selector = KERNEL_CODE_SELECTOR;
    _idt[1].zero = 0;
    _idt[1].flags = IDT_FLAG_INT32;

    _idt[12].lower = (base12 & 0xffff);
    _idt[12].higher = (base12 >> 16) & 0xffff;
    _idt[12].selector = KERNEL_CODE_SELECTOR;
    _idt[12].zero = 0;
    _idt[12].flags = IDT_FLAG_INT32;

    RemapPIC();

    outportb(pic1_data, PIC1_MASK);
    outportb(pic2_data, PIC2_MASK);

    LoadIDT();
}
