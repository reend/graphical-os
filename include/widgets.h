#ifndef WIDGETS_H
#define WIDGETS_H

#define WINDOW_TITLEBAR_H     20
#define WINDOW_CLOSE_BTN_RADIUS 8

int DrawCircleButton(int x, int y, int radius, int r, int g, int b);
int DrawButton(int x, int y, int width, int height, int r, int g, int b, char* text, int r1, int g1, int b1);
int DrawWindow(int* x, int* y, int* width, int* height, int r, int g, int b, int* mouse_held, int* grab_dx, int* grab_dy);

#endif
