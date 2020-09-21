//Greg Ryterski
//gjr7dz, 18186949
//Lab 9 main, Group E
#include "lab9.h"

void errorCheck(int value);

int main(void){
  Student* head = initListWithDummyNode();
  int errorChecker = 0;
  int headVal, tailVal, x;
  do{
    printf("Menu:\n");
    printf("1) Add age to the head of the list\n");
    printf("2) Add age to the tail of the list\n");
    printf("3) Print List\n");
    printf("4) Empty List\n");
    printf("5) Exit\n");
    scanf("%d", &x);

    if(x == 1){
      printf("Enter value to add to the head: ");
      scanf("%d", &headVal);
      errorChecker = insertToHead(head, headVal);
      errorCheck(errorChecker);
    }

    if(x == 2){
      printf("Enter value to add to the tail: ");
      scanf("%d", &tailVal);
      errorChecker = insertToTail(head, tailVal);
      errorCheck(errorChecker);
    }

    if(x == 3){
      printf("\nList: ");
      printList(head);
      puts("");
    }

    if(x == 4)
      emptyList(head);

    if(x<1 || x>5)
      printf("Must enter a value 1-3\n");
  }while(x != 5);

  freeList(head);
}

void errorCheck(int value){
  if(value == 0){
    printf("Insertion failed.\n\n");
  }

  if(value == 1){
    printf("Insertion was successful.\n\n");
  }
}
