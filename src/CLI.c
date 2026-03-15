// Ad Maiorem Dei Gloriam!

#include "CLI.h"
#include "tasks.h"
#include <stdio.h>

void printTasks(struct taskPool *head) {
  struct taskPool *currentTP = head;
  int numTask = 0;
  
  while (currentTP != NULL) {
    for (int taskIndexTP = 0; taskIndexTP < currentTP->numTasks; taskIndexTP++) {
      char colorCode[] = "\033[0;00m";
      if (currentTP->tasks[taskIndexTP].completed) {
        // Green ANSI escape color code
        colorCode[4] = '3';
        colorCode[5] = '2';
      }
      printf("%s%d. %s\033[0m\n", colorCode, numTask, currentTP->tasks[taskIndexTP].text);
      numTask++;
    }

    currentTP = currentTP->next;
  }
}

void takeAction(char *inputBuffer, char *argumentBuffer) {
  printf("What do you want to do? (write HELP for more information).\n");

  fgets(inputBuffer, 261, stdin);
  inputBuffer[strcspn(inputBuffer, "\n")] = 0;

  char *tempCmdBuffer = strtok(inputBuffer, " ");
  if (tempCmdBuffer == NULL) {
    inputBuffer[0] = '\0';
    return;
  }

  strcpy(inputBuffer, tempCmdBuffer);

  char *tempArgBuffer = strtok(NULL, "");
  if (tempArgBuffer == NULL) {
    argumentBuffer[0] = '\0';
  } else {
    strcpy(argumentBuffer, tempArgBuffer);
  }
}

enum ACTIONS breakAction(char *input) {
  if (strncasecmp("list", input, 4) == 0) return LIST;
  if (strncasecmp("create", input, 6) == 0) return CREATE;
  if (strncasecmp("delete", input, 6) == 0) return DELETE;
  if (strncasecmp("help", input, 4) == 0) return HELP;
  if (strncasecmp("exit", input, 4) == 0) return EXIT;
  if (strncasecmp("complete", input, 8) == 0) return COMPLETE;
  return INVALID_ACTION;
};

void processAction(enum ACTIONS action, char *argument, struct taskPool *head) {
  switch(action) {
    case LIST:
      printTasks(head);
      break;
    case CREATE:
      insertTask(head, argument);
      break;
    case DELETE: ;
      int delSuccess = deleteTask(head, atoi(argument));
      if (delSuccess == E_OUT_OF_RANGE) {
        printf("Error: Out of range index.\n-------\n");
      }
      break;
    case HELP:
      printf(
        "Available commands:\n"
                "  List - Lists all tasks.\n"
                "  Create <task> - Creates a task and assing them a ID!\n"
                "  Delete <taskId> - Deletes a task with the assingned ID.\n"
                "  Help - Shows this message.\n"
                "  Exit - Exits the program.\n"
                "  Complete <taskId> - Marks a task as concluded.\n"
                "-------\n"
      );
      break;

    case EXIT:
      printf("Would you like to save the file? ");
      char saveInput;
      scanf(" %c", &saveInput);

      if (saveInput == 'n') {
        exit(0);
      } else {
        // saveToDisk()
        exit(0);
      }
      break;
    case COMPLETE: ;
      int completeSuccess = completeTask(head, atoi(argument));
      if (completeSuccess == E_OUT_OF_RANGE) {
        printf("Error: Out of range index.\n-------\n");
      }
      break;
    case INVALID_ACTION:
      printf("Error: Invalid action. Type \"Help\" to view a list of available commands.\n-------\n");
      break;
  }
}
