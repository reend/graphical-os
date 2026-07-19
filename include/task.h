#ifndef TASK_H
#define TASK_H

#define MAX_TASKS         256
#define TASK_PARAMS_SIZE  100
#define TASK_BUFFER_SIZE  100
#define task_param_length 10
#define TASK_MAX_PRIORITY 5

#define IPARAM_X       0
#define IPARAM_Y       1
#define IPARAM_W       2
#define IPARAM_H       3
#define IPARAM_GRAB_DX 4
#define IPARAM_GRAB_DY 5
#define IPARAM_DRAG    9

struct Task
{
    int priority;
    int taskId;
    char ca1[TASK_BUFFER_SIZE];
    int i1;
    int (*function)(int);
};

extern struct Task tasks[MAX_TASKS];
extern int TasksLength;
extern int iparams[TASK_PARAMS_SIZE];

int RegisterTask(int priority, int (*function)(int));
void ProcessTasks();
void CloseTask(int taskId);

int ClearScreenTask(int taskId);
int DrawMouseTask(int taskId);
int HandleKeyboardTask(int taskId);
int TestGraphicalElementsTask(int taskId);
int WelcomeTask(int taskId);

#endif
