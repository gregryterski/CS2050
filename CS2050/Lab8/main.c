#include "Lab8.h"

int main(void){
  Student * head;
  int a = 72;
  int b = 15;
  head=initList();

  head=addToHead(head, b);
  for(int x=0;x<20;x++){
      head=addToTail(head, x+20);
  }
  head=addToTail(head, a);

  printf("Current List: ");
  printList(head);

  printf("Inserting new numbers to the head and tail of the list.\n");
  head = addToHead(head, 13);
  head = addToTail(head, 89);

  printf("New list: ");
  printList(head);

  int ageChecker = searchAge(head, 22);
  if(ageChecker==-1){
    printf("There is no age 22 in the list.\n");
  }
  else
  {
  printf("The age of 22 is located at %d in the list(0-based).\n", ageChecker);
  }
  head=freeList(head);

  if(head==NULL)
      printf("Memory is deallocated\n");
}
