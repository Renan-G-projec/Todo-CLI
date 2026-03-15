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

void deleteTask(struct taskPool *head, int index) { 
  struct taskPool *taskTP = NULL;
  uint8_t currentTaskIndex = 0;

  getTPandIndex(head, index, &taskTP, &currentTaskIndex);

  taskTP->numTasks--;
  for (int i = currentTaskIndex; i < taskTP->numTasks; i++) {
    taskTP->tasks[i] = taskTP->tasks[i + 1];
  }  
}

void completeTask(struct taskPool *head, int index) {
  struct taskPool *taskPool = NULL;
  uint8_t taskIndexTP = 0;

  getTPandIndex(head, index, &taskPool, &taskIndexTP);

  taskPool->tasks[taskIndexTP].completed = 1;
}

void getTPandIndex(struct taskPool *head, int index, struct taskPool **destTP, uint8_t *destIdx) {
  struct taskPool *currentTP = head;
  int i = 0;
  uint8_t currentTaskIndex = 0;
  while (i < index) {
    if (currentTaskIndex >= currentTP->numTasks - 1) {
      if (currentTP->next == NULL) {
        return;
      }

      currentTP = currentTP->next;
      currentTaskIndex = 0;
    } else {
      currentTaskIndex++;
    }
    i++;
  }

  *destTP = currentTP;
  *destIdx = currentTaskIndex;
}
