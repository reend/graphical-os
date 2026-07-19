#ifndef PIC_H
#define PIC_H

#define pic1_command 0x20
#define pic1_data    0x21
#define pic2_command 0xa0
#define pic2_data    0xa1

#define icw1_def  0x10
#define icw1_icw4 0x01
#define icw4_x86  0x01

#define PIC_EOI   0x20

#define PIC1_MASK 0b11111001
#define PIC2_MASK 0b11101111

void RemapPIC();

#endif
