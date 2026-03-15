// Ad Maiorem Dei Gloriam!
#ifndef TASKS_H
#define TASKS_H

// Macros
#define TASK_SIZE 256
#define TASKS_IN_POOL 16

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

struct task {
  char text[TASK_SIZE];
};

struct taskPool {
  struct task tasks[TASKS_IN_POOL];
  struct taskPool *next;
  uint8_t numTasks;
};

// Allocates the memory to handle the struct
struct taskPool *createTaskPool(struct taskPool *head);
void deleteTaskPool(struct taskPool* head);

void insertTask(struct taskPool *taskPoolHead, const char* text);
void deleteTask(struct taskPool *head, int index);

#endif
