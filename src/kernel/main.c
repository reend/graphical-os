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

   base = (unsigned int)&isr1;
   base12 = (unsigned int)&isr12;

   InitialiseMouse();
   InitialiseIDT();

   tasks[TasksLength].priority = 0;
   tasks[TasksLength].taskId = TasksLength;
   tasks[TasksLength].function = &ClearScreenTask;
   TasksLength++;

   tasks[TasksLength].priority = 0;
   tasks[TasksLength].taskId = TasksLength;
   tasks[TasksLength].function = &TestGraphicalElementsTask;
   iparams[TasksLength * task_param_length + 0] = 10;
   iparams[TasksLength * task_param_length + 1] = 10;
   iparams[TasksLength * task_param_length + 2] = 300;
   iparams[TasksLength * task_param_length + 3] = 300;
   TasksLength++;
   
   tasks[TasksLength].priority = 0;
   tasks[TasksLength].taskId = TasksLength;
   tasks[TasksLength].function = &HandleKeyboardTask;
   TasksLength++;

   tasks[TasksLength].priority = 0;
   tasks[TasksLength].taskId = TasksLength;
   tasks[TasksLength].function = &DrawMouseTask;
   TasksLength++;

   while(1)
   {
        ProcessTasks();
        Flush();
   }
}
