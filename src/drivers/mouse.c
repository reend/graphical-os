#include "mouse.h"
#include "ports.h"
#include "ps2.h"
#include "vbe.h"

volatile int mx, my;
volatile int left_clicked, right_clicked, middle_clicked;

static volatile int current_byte;
static volatile uint8_t bytes[4];
static volatile int mouse_speed;

void MouseWait(unsigned char type) {
    int time_out = 100000;

    if (type == 0) {
        while (time_out--) {
            if ((inportb(PS2_STATUS) & 1) == 1)
                return;
        }
        return;
    }
    else {
        while (time_out--) {
            if ((inportb(PS2_STATUS) & 2) == 0)
                return;
        } 
        return;
    }
}

void MouseWrite(unsigned char data) {
    MouseWait(1);
    outportb(PS2_CMD, PS2_CMD_WRITE_MOUSE);

    MouseWait(1);
    outportb(PS2_DATA, data);
}

unsigned char MouseRead() {
    MouseWait(0);
    return inportb(PS2_DATA);
}

void InitialiseMouse() {
    unsigned char status;

    current_byte = 0;
    mouse_speed = 3;

    MouseWait(1);
    outportb(PS2_CMD, PS2_CMD_ENABLE_AUX);

    MouseWait(1);
    outportb(PS2_CMD, PS2_CMD_READ_CONFIG);
    MouseWait(0);
    status = (inportb(PS2_DATA) | 2) & ~0x20;
    MouseWait(1);
    outportb(PS2_CMD, PS2_CMD_WRITE_CONFIG);
    MouseWait(1);
    outportb(PS2_DATA, status);

    MouseWrite(MOUSE_CMD_SET_DEFAULTS);
    MouseRead();

    MouseWrite(MOUSE_CMD_ENABLE);
    MouseRead();
}

void HandleMousePacket();
void HandleMouseInterrupt() {
    uint8_t byte = inportb(PS2_DATA);

    if (current_byte == 0 && !(byte & always_set))
        return;

    bytes[current_byte] = byte;
    current_byte++;

    if (current_byte >= 3) {
        current_byte = 0;
        HandleMousePacket();
    }
}

void HandleMousePacket() {
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;

    uint8_t status = bytes[0];
    int32_t change_x = (int32_t) bytes[1];
    int32_t change_y = (int32_t) bytes[2];

    if ((status & x_overflow) || (status & y_overflow))
        return;

    if (status & x_negative)
        change_x |= 0xffffff00;

    if (status & y_negative)
        change_y |= 0xffffff00;

    left_clicked = status & left_click;
    right_clicked = status & right_click;
    middle_clicked = status & middle_click;

    mx += change_x * mouse_speed;
    my -= change_y * mouse_speed;

    if (mx < 0) mx = 0;
    else if (mx >= VBE->x_resolution) mx = VBE->x_resolution - 1;

    if (my < 0) my = 0;
    else if (my >= VBE->y_resolution) my = VBE->y_resolution - 1;
}
