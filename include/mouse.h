#ifndef MOUSE_H
#define MOUSE_H

#include "types.h"

#define y_overflow   0b10000000
#define x_overflow   0b01000000
#define y_negative   0b00100000
#define x_negative   0b00010000
#define always_set   0b00001000
#define middle_click 0b00000100
#define right_click  0b00000010
#define left_click   0b00000001

extern volatile int mx, my;
extern volatile int left_clicked, right_clicked, middle_clicked;

void InitialiseMouse();
void HandleMouseInterrupt();

#endif
