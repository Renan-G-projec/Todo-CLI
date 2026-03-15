// Ad Maiorem Dei Gloriam!
#ifndef CLI_H
#define CLI_H

// Macros
#define RESPONSE_BUFF 262 // 255 for the task, 7 for the action.

// Includes
#include <strings.h>
#include "tasks.h"

enum ACTIONS {
  LIST,
  CREATE,
  DELETE,
  HELP,
  EXIT,
  COMPLETE,
  INVALID_ACTION
};

void printTasks(struct taskPool *head);
void takeAction(char *inputBuffer, char *argument);

enum ACTIONS breakAction(char *input);

void processAction(enum ACTIONS action, char *argumentBuffer, struct taskPool *head);

#endif
