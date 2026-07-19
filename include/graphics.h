#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "vbe.h"

int rgb(int r, int g, int b);
void Draw(int x, int y, int r, int g, int b);
void ClearScreen(int r, int g, int b);
void DrawRect(int x, int y, int width, int height, int r, int g, int b);
void DrawCircle(int x, int y, int radius, int r, int g, int b);
void DrawMouse(int x, int y, int r, int g, int b);
void Flush();

#endif
