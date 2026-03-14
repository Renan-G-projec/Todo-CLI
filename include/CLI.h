// Ad Maiorem Dei Gloriam!
#ifndef CLI_H
#define CLI_H

// Macros
#define RESPONSE_BUFF 262 // 255 for the task, 7 for the action.

// Includes
#include <strings.h>
#include "tasks.h"

enum ACTIONS {
  CREATE,
  DELETE,
  HELP,
  INVALID_ACTION
};

void printTasks(struct taskPool *head);
void takeAction(char *inputBuffer);

enum ACTIONS breakAction(char *input);

void processAction(enum ACTIONS action);

#endif
