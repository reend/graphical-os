#ifndef KEYBOARD_H
#define KEYBOARD_H

extern int Scancode;

extern int shift_pressed;
extern int caps_pressed;
extern int escape_pressed;
extern int backspace_pressed;
extern int alt_pressed;
extern int ctrl_pressed;
extern int enter_pressed;

unsigned char ProcessScancode(int scancode);

#endif
