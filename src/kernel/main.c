#include "vbe.h"
#include "graphics.h"
#include "idt.h"
#include "mouse.h"
#include "task.h"

int start() 
{
   VBEInfoBlock* VBE = (VBEInfoBlock*) VBEInfoAddress;

   mx = VBE->x_resolution / 2;
   my = VBE->y_resolution / 2;

   InitialiseMouse();
   InitialiseIDT();

   RegisterTask(0, &ClearScreenTask);

   int window = RegisterTask(0, &TestGraphicalElementsTask);
   iparams[window * task_param_length + IPARAM_X] = 10;
   iparams[window * task_param_length + IPARAM_Y] = 10;
   iparams[window * task_param_length + IPARAM_W] = 300;
   iparams[window * task_param_length + IPARAM_H] = 300;

   RegisterTask(0, &HandleKeyboardTask);
   RegisterTask(0, &DrawMouseTask);

   while(1)
   {
        ProcessTasks();
        Flush();
   }
}
