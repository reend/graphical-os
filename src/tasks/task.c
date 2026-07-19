#include "task.h"

int TasksLength = 0;

struct Task tasks[MAX_TASKS];
int iparams[TASK_PARAMS_SIZE] = {10};

int RegisterTask(int priority, int (*function)(int))
{
    int id = TasksLength;

    tasks[id].priority = priority;
    tasks[id].taskId = id;
    tasks[id].function = function;

    TasksLength++;

    return id;
}

void ProcessTasks()
{
    int priority = 0;

    while (priority <= TASK_MAX_PRIORITY)
    {
        for (int i = 0; i < TasksLength; i++)
        {
            if (tasks[i].priority == priority)
            {
                tasks[i].function(tasks[i].taskId);
            }
        }
        priority++;
    }
}

void CloseTask(int taskId)
{
    for (int i = taskId; i < TasksLength - 1; i++)
    {
        tasks[i] = tasks[i+1];
    }

    TasksLength--;
}
