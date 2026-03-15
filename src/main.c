// Ad Maiorem Dei Gloriam!

// Includes
#include "CLI.h"
#include "tasks.h"

int main() {
  struct taskPool *mainTP = createTaskPool(NULL);

  char inputBuff[RESPONSE_BUFF];
  char argBuffer[RESPONSE_BUFF];
  while (1) {
    takeAction(inputBuff, argBuffer);

    int action = breakAction(inputBuff);
    processAction(action, argBuffer, mainTP);
  }
  return 0;
}
