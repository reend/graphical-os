#include "graphics.h"

#define CURSOR_WIDTH  10
#define CURSOR_HEIGHT 10

void DrawMouse(int x, int y, int r, int g, int b)
{
    int mouse[] = {
        0x3FF,
        0x3FE,
        0x3FC,
        0x3F8,
        0x3F0,
        0x3E0,
        0x3C0,
        0x380,
        0x300,
        0x200
    };

    int mouse_width = CURSOR_WIDTH, mouse_height = CURSOR_HEIGHT;

    for (int j = 0; j < mouse_height; j++)
    {
        unsigned int row = mouse[j];
        int shift = mouse_width - 1;
        int bit_val = 0;

        for (int i = 0; i < mouse_width; i++)
        {
            bit_val = (row >> shift) & 0x1;
            if (bit_val == 1)
            {
                Draw(x + i, y + j, r, g, b);
            }

            shift -= 1;
        }
    }
}
