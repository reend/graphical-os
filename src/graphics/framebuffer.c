#include "graphics.h"
#include "colors.h"

int rgb(int r, int g, int b)
{
    return r << RGB565_RED_SHIFT | g << RGB565_GREEN_SHIFT | b;
}

void Draw(int x, int y, int r, int g, int b)
{
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;
    unsigned short* buffer = (unsigned short*) ScreenBufferAddress;

    int index = y * VBE->x_resolution + x;
    *(buffer + index) = rgb(r, g, b);
}

void ClearScreen(int r, int g, int b)
{
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;
    for (int y = 0; y < VBE->y_resolution; y++)
    {
        for (int x = 0; x < VBE->x_resolution; x++)
        {
            Draw(x, y, r, g, b);
        }
    }
}

void Flush()
{
    VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;
    unsigned short* buffer = (unsigned short*) ScreenBufferAddress;
    int index;

    for (int y = 0; y < VBE->y_resolution; y++)
    {
        for (int x = 0; x < VBE->x_resolution; x++)
        {   
            int index = y * VBE->x_resolution + x;
            *((unsigned short*)VBE->screen_ptr + index) = *(buffer + index);
        }
    }
}
