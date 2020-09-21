//Greg Ryterski
//gjr7dz, 18186949
//Lab 12 main
#include "lab12.h"

int main(void){
  PQueue headQ = initPQueue();
  Student* randoNode = createNode(1, 10);
  if(randoNode == NULL)
    return 0;

  printf("RandoNode:\nPriority: %.2f\nAge: %d\n", randoNode->priority, randoNode->age);
  int errorCheck = 0;

  errorCheck = insertPQ(4.68, 22, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorCheck = insertPQ(7.20, 18, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorCheck = insertPQ(6.05, 15, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorCheck = insertPQ(0.74, 16, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }


  errorCheck = insertPQ(2.48, 21, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }


  printf("\nDecending Order:\n");
  printPQueue(headQ);

  Student* delMin = deleteMin(headQ);
  Student* delMax = deleteMax(headQ);
  printf("\nDecending Order(deleted Min & Max):\n");
  printPQueue(headQ);
  printf("Deleted Min:\nPriority: %.2f\nAge: %d\n", delMin->priority, delMin->age);
  printf("\nDeleted Max:\nPriority: %.2f\nAge: %d\n", delMax->priority, delMax->age);
  Student* newMin = returnMin(headQ);
  Student* newMax = returnMax(headQ);
  printf("\nNew Min:\nPriority: %.2f\nAge: %d\n", newMin->priority, newMin->age);
  printf("\nNew Max:\nPriority: %.2f\nAge: %d\n", newMax->priority, newMax->age);
  freePQueue(headQ);
}
