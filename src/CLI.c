// Ad Maiorem Dei Gloriam!

#include "CLI.h"
void printTasks(struct taskPool *head) {
  struct taskPool *currentTP = head;
  int numTask = 0;
  
  while (currentTP != NULL) {
    for (int taskIndexTP = 0; taskIndexTP < currentTP->numTasks; taskIndexTP++) {
      printf("%d. %s\n", numTask, currentTP->tasks[taskIndexTP].text);
      numTask++;
    }

    currentTP = currentTP->next;
  }
}

void takeAction(char *inputBuffer) {
  printf("What do you want to do? (write HELP for more information).\n");

  scanf("%261s", inputBuffer);
}

enum ACTIONS breakAction(char *input) {
  if (strncasecmp("create", input, 6) == 0) return CREATE;
  if (strncasecmp("delete", input, 6) == 0) return DELETE;
  if (strncasecmp("help", input, 4) == 0) return HELP;
  return INVALID_ACTION;
};

void processAction(enum ACTIONS action) {
  switch(action) {
    case CREATE:
      
      break;
    case DELETE:

      break;
    case HELP:
      printf(
        "Available commands:\n"
                "  Create <task> - Creates a task and assing them a ID!\n"
                "  Delete <taskId> - Deletes a task with the assingned ID.\n"
                "  Help - Shows this message.\n"
      );
      break;
    case INVALID_ACTION:
      printf("Error: Invalid action. Type \"Help\" to view a list of available commands.\n");
      break;
  }
}
