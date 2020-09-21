//Greg Ryterski
//gjr7dz, 18186949
//Lab 9, Group E
#include "lab9.h"

/*Initializes an empty list containing two dummy nodes: one at the head and one
at the tail. Linked-list is empty with no ages.*/
Student* initListWithDummyNode(){
  Student* tailDummy = malloc(sizeof(Student));
  if(tailDummy == NULL){
    printf("Malloc has failed to allocate memory.\n");
    return NULL;
  }
  tailDummy->nextPtr = NULL;

  Student* headDummy = malloc(sizeof(Student));
  if(headDummy == NULL){
    printf("Malloc has failed to allocate memory.\n");
    free(tailDummy);
    return NULL;
  }
  headDummy->nextPtr = tailDummy; //sets the pointer of the head to the tail for time being

  return headDummy;
}

/*Function recieves a linked-list and the desired age to be added to the head
of the list. The function adds the age to the front of the current list and
returns a 1 if successful and 0 if it is unsuccessful.*/
int insertToHead(Student* stud, int age){
  Student* head = malloc(sizeof(Student));
  if(head == NULL){
    printf("Malloc has failed to allocate memory.\n");
    return 0; //happens if malloc fails
  }

  head->age = age;
  head->nextPtr = stud->nextPtr;
  stud->nextPtr = head; //inserts the new node to the front of the list

  return 1;
}

/*Function recieves a linked-list and the desired age to be added to the tail
of the list. The function adds the age to the end of the current list and
returns a 1 if successful and - if it is unsuccessful.*/
int insertToTail(Student* stud, int age){
  Student* tail = malloc(sizeof(Student));
  if(tail == NULL){
    printf("Malloc has failed to allocate memory.\n");
    return 0;
  }

  while(stud->nextPtr != NULL){ //moves the student pointer to the tail
    stud = stud->nextPtr;
  }

  stud->age = age;
  stud->nextPtr = tail; //inserts the new node to the tail of the list
  tail->nextPtr = NULL;

  return 1;
}

/*Function recieves a current linked-list and prints all the values stored.*/
void printList(Student* stud){
  Student* pStud;
  if(stud->nextPtr == NULL){
    printf("There is nothing in this list.\n"); //can't print a list that is empty
  }
  else
  {
    for(pStud = stud->nextPtr; pStud->nextPtr != NULL; pStud = pStud->nextPtr){
      printf("%d ", pStud->age);
    }
    puts("");
  }
}

/*Function recieves a current linked-list and frees the memories for all real
nodes while leaving the two dummy nodes untouched.*/
void emptyList(Student* stud){
  Student* emptyStud = NULL; //struct is used to free memories in the list
  if(stud->nextPtr->nextPtr == NULL){
    printf("The list is already empty.\n"); //list is already empty
  }
  else
  {
    while(stud->nextPtr->nextPtr != NULL){
      emptyStud = stud->nextPtr;
      stud->nextPtr = stud->nextPtr->nextPtr; //moves to the next position in the list
      free(emptyStud);
    }
    printf("List is now empty.\n");
  }
}

/*This function recieves a current linked-list and frees all allocated memory
with the list.*/
void freeList(Student* stud){
  Student* filler;
  while(stud != NULL){
    filler = stud;
    stud = stud->nextPtr; //shifts to the next node
    free(filler);
  }
}
