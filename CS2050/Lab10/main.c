//Greg Ryterski
//gjr7dz, 18186949
//Lab10 main
#include "lab10.h"

int main(void){
  StudentList *head = initStack();
  if(head == NULL){
    printf("Malloc has failed.\n");
    return 0;
  }

  int errorCount = 0;
  errorCount = pushStack(head, 50);
  if(errorCount == -1){
    return 0;
  }
  errorCount = pushStack(head, 40);
  if(errorCount == -1){
    return 0;
  }
  errorCount = pushStack(head, 30);
  if(errorCount == -1){
    return 0;
  }
  errorCount = pushStack(head, 20);
  if(errorCount == -1){
    return 0;
  }

  printf("\n\nStack\n");
  printList(head);
  Student* pStack = popStack(head);
  printf("Popped value from the stack = %d\n", pStack->age);
  printList(head);

  StudentList* pQueue = initQueue();

  errorCount = enQueue(pQueue, 100);
  if(errorCount == -1){
    return 0;
  }

  errorCount = enQueue(pQueue, 90);
  if(errorCount == -1){
    return 0;
  }

  errorCount = enQueue(pQueue, 80);
  if(errorCount == -1){
    return 0;
  }

  errorCount = enQueue(pQueue, 70);
  if(errorCount == -1){
    return 0;
  }

  printf("\n\nQueue\n");
  printList(pQueue);
  printf("Removing earliest struct.\n");
  Student* dQueue = deQueue(pQueue);
  printf("deQueued node: %d\n", dQueue->age);
  printList(pQueue);

  freeList(head);
}
