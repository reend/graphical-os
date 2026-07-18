#include "graphics.h"

int start() 
{

   char str1[] = "Welcome to GraphOS!\n\nText rendered by custom library";
   char *p = str1;


   while(1)
   {
        ClearScreen(181.0f / 255.0f * 16.0f, 232.0f / 255.0f * 32.0f, 255.0f / 255.0f * 16.0f);
        DrawString(getArialCharacter, font_arial_width, font_arial_height, p, 100, 100, 0, 0, 0);
        Flush();
   }
}