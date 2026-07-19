#include "graphics.h"

void DrawRect(int x, int y, int width, int height, int r, int g, int b)
{
    for (int j = y; j < (y + height); j++)
    {
        for (int i = x; i < (x + width); i++)
        {
            Draw(i, j, r, g, b);
        }
    }
}

void DrawCircle(int x, int y, int radius, int r, int g, int b)
{
    int rr = radius * radius;

    for (int j = -radius; j < radius; j++)
    {
        for (int i = -radius; i < radius; i++)
        {
            if ((i * i + j * j) <= rr)
            {
                Draw(x + i, y + j, r, g, b);
            }
        }
    }
}
