#include "isr.h"
#include "ports.h"
#include "pic.h"
#include "ps2.h"
#include "keyboard.h"
#include "mouse.h"

void HandleISR1() {
    Scancode = inportb(PS2_DATA);
    outportb(pic2_command, PIC_EOI);
    outportb(pic1_command, PIC_EOI);
}

void HandleISR12() {
    HandleMouseInterrupt();
    outportb(pic2_command, PIC_EOI);
    outportb(pic1_command, PIC_EOI);
}
