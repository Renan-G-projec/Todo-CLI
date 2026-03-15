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

  while (!inserted) {
    if (currentTP->numTasks >= TASKS_IN_POOL) {
      struct taskPool *nextTP = currentTP->next;
      if (nextTP == NULL) {
        nextTP = createTaskPool(currentTP);
      }
      currentTP = nextTP;
    } else {
      // Inserting the task in the taskPool;
      memcpy(currentTP->tasks[currentTP->numTasks].text, text,
             strlen(text) + 1);
      currentTP->numTasks++;
      inserted = 1;
    }
  }
}

int deleteTask(struct taskPool *head, int index) {
  struct taskPool *taskTP = NULL;
  uint8_t currentTaskIndex = 0;

  int tpIdxSucess = getTPandIndex(head, index, &taskTP, &currentTaskIndex);
  if (tpIdxSucess != 0)
    return tpIdxSucess;

  taskTP->numTasks--;
  for (int i = currentTaskIndex; i < taskTP->numTasks; i++) {
    taskTP->tasks[i] = taskTP->tasks[i + 1];
  }
  return 0;
}

int completeTask(struct taskPool *head, int index) {
  struct taskPool *taskPool = NULL;
  uint8_t taskIndexTP = 0;

  int tpIdxSuccess = getTPandIndex(head, index, &taskPool, &taskIndexTP);
  if (tpIdxSuccess != 0)
    return tpIdxSuccess;

  taskPool->tasks[taskIndexTP].completed = 1;
  return 0;
}

int getTPandIndex(struct taskPool *head, int index, struct taskPool **destTP,
                  uint8_t *destIdx) {
  struct taskPool *currentTP = head;
  while (index > currentTP->numTasks) {
    index -= currentTP->numTasks;
    currentTP = currentTP->next;
    if (currentTP == NULL) {
      return E_OUT_OF_RANGE;
    }
  }

  if (currentTP->numTasks <= index)
    return E_OUT_OF_RANGE;

  *destTP = currentTP;
  *destIdx = index;
  return 0;
}
