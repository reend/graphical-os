#include "widgets.h"
#include "graphics.h"
#include "text.h"
#include "font.h"
#include "mouse.h"
#include "colors.h"
#include "types.h"

int DrawCircleButton(int x, int y, int radius, int r, int g, int b)
{
    if ((mx - x)*(mx - x) + (my - y)*(my - y) <= radius*radius)
    {
        DrawCircle(x, y, radius, r, g, b); 

        if (left_clicked == TRUE)
        {
            left_clicked = FALSE;
            return 1;
        }
    } 
    else 
    {
        DrawCircle(x, y, radius, r/4, g/4, b/4);
    }

    return 0;   
}

int DrawButton(int x, int y, int width, int height, int r, int g, int b, char* text, int r1, int g1, int b1)
{
    if (mx > x && mx < x + width && my > y && my < my + height)
    {
        DrawRect(x, y, width, height, r, g, b);

        if (left_clicked == TRUE)
        {
            left_clicked = FALSE;
            return 1;
        }
    }
    else
    {
        DrawRect(x, y, width, height, r/4, g/4, b/4);        
    }

    DrawString(getArialCharacter, font_arial_width, font_arial_height, text, x + width / 10, y + height / 10, r1, g1, b1);
}

int DrawWindow(int* x, int* y, int* width, int* height, int r, int g, int b, int* mouse_held)
{
    if (left_clicked == FALSE)
    {
       *mouse_held = FALSE;
    }

    if (*mouse_held == TRUE || 
        (left_clicked == TRUE && mx > *x &&
        mx < *x + *width - 30 &&
        my > *y && 
        my < *y + WINDOW_TITLEBAR_H))
        {
            left_clicked = FALSE;
            *mouse_held = TRUE;
            *x = mx - (*width / 2);
            *y = my - 10;
        } 

    DrawRect(*x, *y, *width, WINDOW_TITLEBAR_H, COLOR_TITLEBAR_R, COLOR_TITLEBAR_G, COLOR_TITLEBAR_B);
    DrawRect(*x, *y + WINDOW_TITLEBAR_H, *width, *height, r, g, b);

    return DrawCircleButton(*x + *width - 10, *y + 10, WINDOW_CLOSE_BTN_RADIUS, COLOR_CLOSE_BTN_R, COLOR_CLOSE_BTN_G, COLOR_CLOSE_BTN_B);
}
