// Ad Maiorem Dei Gloriam!

// Includes
#include "tasks.h"

struct taskPool *createTaskPool(struct taskPool *head) {
  struct taskPool *newTP = (struct taskPool *)malloc(sizeof(struct taskPool));

  if (newTP == NULL) {
    printf("Error: Could not initialize taskPool.\nNull memory allocation.");
    return NULL;
  }

  newTP->numTasks = 0;
  if (head == NULL) {
    newTP->next = NULL;
    return newTP;
  }

  newTP->next = head->next;
  head->next = newTP;
  return newTP;
}

void deleteTaskPool(struct taskPool *head) {
  struct taskPool *delTP = head->next;
  
  head->next = delTP->next;
  free(delTP);
}


void insertTask(struct taskPool *taskPoolHead, const char *text) {
  struct taskPool *currentTP = taskPoolHead;
  unsigned char inserted = 0;

  while(!inserted) {
    if (currentTP->numTasks >= TASKS_IN_POOL) {
      struct taskPool *nextTP = currentTP->next;
      if (nextTP == NULL) {
        nextTP = createTaskPool(currentTP);
      }
      currentTP = nextTP;
    } else {
      // Inserting the task in the taskPool;
      memcpy(currentTP->tasks[currentTP->numTasks].text, text, strlen(text) + 1);
      currentTP->numTasks++;
      inserted = 1;
    }
  }
}

void deleteTask(struct taskPool *taskPool, uint8_t index) { 
  while (index < TASKS_IN_POOL) {
    taskPool->tasks[index] = taskPool->tasks[index + 1];
    index++;
  }
}
