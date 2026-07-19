#include "task.h"
#include "graphics.h"
#include "text.h"
#include "font.h"
#include "keyboard.h"
#include "mouse.h"
#include "widgets.h"
#include "colors.h"
#include "types.h"

int ClearScreenTask(int taskId)
{
    ClearScreen(COLOR_DESKTOP_R, COLOR_DESKTOP_G, COLOR_DESKTOP_B);
    return 0;
}

int DrawMouseTask(int taskId)
{
    DrawMouse(mx, my, COLOR_CURSOR_R, COLOR_CURSOR_G, COLOR_CURSOR_B);
    return 0;
}

int HandleKeyboardTask(int taskId)
{
    char* characterBuffer = tasks[taskId].ca1; 
    int* characterBufferLength = &tasks[taskId].i1;

    char character = ProcessScancode(Scancode);

    if (backspace_pressed == TRUE) {
        characterBuffer[*characterBufferLength - 1] = '\0';
        (*characterBufferLength)--;
        backspace_pressed = FALSE;
        Scancode = -1;
    } 
    else if (character != '\0' && *characterBufferLength < TASK_BUFFER_SIZE - 1)
    {
     characterBuffer[*characterBufferLength] = character;
     characterBuffer[*characterBufferLength + 1] = '\0';
     (*characterBufferLength)++;
     Scancode = -1;
    }

    DrawString(getArialCharacter, font_arial_width, font_arial_height, characterBuffer, 100, 100, COLOR_TEXT_R, COLOR_TEXT_G, COLOR_TEXT_B);

    return 0;
}

int TestGraphicalElementsTask(int taskId)
{
        if (DrawWindow(
            &iparams[taskId * task_param_length + IPARAM_X],
            &iparams[taskId * task_param_length + IPARAM_Y],
            &iparams[taskId * task_param_length + IPARAM_W],
            &iparams[taskId * task_param_length + IPARAM_H],
            0, 
            0, 
            0,
            &iparams[taskId * task_param_length + IPARAM_DRAG],
            &iparams[taskId * task_param_length + IPARAM_GRAB_DX],
            &iparams[taskId * task_param_length + IPARAM_GRAB_DY]
        ) == 1)
        {
            CloseTask(taskId);
        }

        return 0;
}
