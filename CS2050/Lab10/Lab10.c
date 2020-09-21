//Greg Ryterski
//gjr7dz, 18186949
//Lab 10
#include "lab10.h"

/*Initializes an empty stack with head and tail members pointing to NULL*/
StudentList* initStack(){
  StudentList* sList = malloc(sizeof(StudentList));
	if(sList == NULL){ //Checks to see if malloc didn't allocate memory
		printf("Malloc has failed.\n");
		return NULL;
	}

	sList->head = NULL;
	sList->tail = NULL;

	return sList; //returns the empty stack
}

/*Function is used to push ages onto the top of the stack that is given along
with the age to add. Returns 1 if insertion is successful and -1 if it fails*/
int pushStack(StudentList* sList,int pValue){
  Student* pushS = malloc(sizeof(Student));
  if(pushS == NULL){ //Checks on malloc and returns -1 if it fails
    printf("Malloc has failed.\n");
    return -1;
  }

  pushS->age = pValue; //sets the new nodes value equal to the age given by the user
  pushS->nextPtr = sList->head;
  sList->head = pushS; //new node is the new head of the list

  if(pushS->nextPtr == NULL){
    sList->tail = pushS;
  }

  return 1; //Returns 1 as a sign that insertion was successful
}

/*Function returns the node that contains the latest "Student" struct with the
appropriate age associated to it. Returns NULL if no struct can be popped.*/
Student* popStack(StudentList* sList){
  Student* pStud = sList->head; //Is the head node of the current list
  if(pStud == NULL){
    printf("There is nothing in this linked list.\n");
    return NULL;
  }
  sList->head = sList->head->nextPtr;

  if(sList->head == NULL){ //Checks if there are no members left in the list
    sList->tail = NULL; //Sets the tail back to NULL since there is nothing in list
  }

  return pStud;
}

/*Intializes an empty queue using "StudentList" struct with the head and tail
being equal to NULL*/
StudentList* initQueue(){
  StudentList* queue = malloc(sizeof(StudentList));
  if(queue == NULL){
    printf("Malloc has failed.\n");
    return NULL;
  }
  queue->head = NULL; //Sets the head to NULL
  queue->tail = NULL; //Sets the tail to NULL
  return queue;
}

/*Function recieves an age and a current linked-list and an age. It adds the age
into the current list at the head and returns a 1 if the insertion was successful and -1
if the insertion failed. */
int enQueue(StudentList* sList,int qValue){
  Student* qStud = malloc(sizeof(Student));
  if(qStud == NULL){
    printf("Malloc has failed.\n");
    return -1;
  }

  qStud->age = qValue; //Sets the new nodes age to the age from the user
  qStud->nextPtr = sList->head; //Moves the head pointer on the new node
  sList->head = qStud;

  if(qStud->nextPtr == NULL){
    sList->tail = qStud;
  }

  return 1;
}

/*Function recieves a current linked-list and dequeues the earliest "Student" struct.
Returns the node if removal is successful and NULL if it fails.*/
Student* deQueue(StudentList* sList){
  Student* qStud = sList->tail;
  Student* newTail = sList->head;
  if(qStud == NULL || newTail == NULL || sList == NULL)
    return NULL;

  if(newTail->nextPtr == NULL){
    sList->head = sList->tail = NULL;
    return qStud;
  }

  while(newTail->nextPtr != sList->tail){ //increments through the list to grab the node before the tail
    newTail = newTail->nextPtr;
  }

  sList->tail->nextPtr = newTail; //sets the new pointer to the item before the original tail
  newTail->nextPtr = NULL; //sets the pointer from the tail to NULL

  return qStud;
}

/*Function prints out all nodes in the linked-list*/
void printList(StudentList* sList){
  Student* pStud = sList->head;
  if(pStud == NULL)
    printf("There is nothing in this linked list.\n");

  while(pStud != NULL){ //Increments through the linked-list
    printf("%d ", pStud->age);
    pStud = pStud->nextPtr;
  }
  printf("\n");
}

/*Function frees all previously allocated memory*/
void freeList(StudentList* sList){
  Student* filler;
  while(sList->head != NULL){
    filler = sList->head; //sets the node to the node at the head of the list
    sList->head = sList->head->nextPtr;
    free(filler); //frees each node
  }
  free(sList); //frees the entire list
}
