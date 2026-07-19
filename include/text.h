#ifndef TEXT_H
#define TEXT_H

void DrawCharacter(int (*f)(int, int), int font_width, int font_height, char character, int x, int y, int r, int g, int b);
void DrawString(int (*f)(int, int), int font_width, int font_height, char* string, int x, int y, int r, int g, int b);

#endif
