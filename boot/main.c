#include "graphics.h"

int start() 
{
   ClearScreen(255, 100, 255);

   DrawCharacter(getArialCharacter, font_arial_width, font_arial_height, 'A', 100, 100, 0, 0, 0);

   while(1);
}