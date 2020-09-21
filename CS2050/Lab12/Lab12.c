//Greg Ryterski
//gjr7dz, 18186949
//Lab 12
#include "lab12.h"

/*Initalizes an empty Priority Queue. All members are initalized and number
of items is set to 0.*/
PQueue initPQueue(){
  PQueue priorityQ;
  priorityQ.list = malloc(sizeof(StudentList));
  if(priorityQ.list == NULL){ //Checks to see if memory allocation has failed.
    printf("Allocation failed.\n");
    return priorityQ;
  }
  else{
    priorityQ.list->head = priorityQ.list->tail = NULL; //Sets the head and tail pointer to NULL
    priorityQ.list->numOfItems = 0;
    return priorityQ;
  }
}

/*Function creates a new Student struct with the given priority number and age
from the user. It sets its next and previous pointer to NULL. Returns NULL if
function failed to create the node.*/
Student* createNode(float priority,int age){
  Student* newNode = malloc(sizeof(Student));
  if(newNode == NULL){
    printf("Allocation failed.\n");
    return NULL;
  }
  else{
    newNode->age = age; //Sets the new nodes age to the age from user
    newNode->priority = priority;
    newNode->nextPtr = NULL;
    newNode->previousPtr = NULL;
    return newNode;
  }
}

/*Inserts a new Student node into the list in O(n) complexity based off its
priority number. The priority is implemented in decending order (highest priority # first).
If the insertion is successful it returns 1, and -1 if unsuccessful.*/
int insertPQ(float priority,int age,PQueue q){
  Student* newNode = createNode(priority,age);
  Student* headNode = q.list->head;
  if(q.list == NULL || newNode == NULL){
    return -1;
  }

  q.list->numOfItems++; //Increases the size number of items in the queue
  if(headNode == NULL){
    q.list->head = q.list->tail = newNode; //If nothing is in the queue the new node is the head and tail
  }
  else if(headNode->nextPtr == NULL){
    if(priority>=headNode->priority){ //Implements the node at the tail if the current head has a higher priority #
      q.list->head = newNode;
      newNode->nextPtr = headNode;
      headNode->previousPtr = newNode;
      headNode->nextPtr = NULL;
    }
    else{
      q.list->tail = newNode;
      headNode->nextPtr = newNode;
      newNode->previousPtr = headNode;
      newNode->nextPtr = NULL;
    }
  }
  else{
    while(headNode->nextPtr != NULL){ //Increments through the list to find where to put the new priority node
      headNode = headNode->nextPtr;
      if(priority>=headNode->priority){
        Student* lastNode = headNode->previousPtr;
        lastNode->nextPtr = newNode;
        newNode->previousPtr = lastNode;
        newNode->nextPtr = headNode;
        headNode->previousPtr = newNode;
        break;
      }
    }

    if(priority<=headNode->priority){ //Adds it to the tail if all previous priorities are greater
      q.list->tail = newNode;
      headNode->nextPtr = newNode;
      newNode->previousPtr = headNode;
    }
  }
  return 1; //Returns 1 if successful
}

/*Function removes the min priority value node from the queue and returns it
back to the user. Function has O(1) complexity. Returns NULL if failed or the
node if successful.*/
Student* deleteMin(PQueue q){
  if(q.list == NULL || q.list->head == NULL)
    return NULL;

  Student* returnNode = q.list->tail; //Tail node holding the min value to be returned
  q.list->numOfItems--; //Subtracts the number of items in the queue

  q.list->tail = q.list->tail->previousPtr; //Sets the new tail to be the previous node
  q.list->tail->nextPtr = NULL;
  return returnNode;
}

/*Function removed the max priority value node form the queue and returns it back
to the user. Function has O(1) complexity. Return NULL if failed or the node if
successful*/
Student* deleteMax(PQueue q){
  if(q.list == NULL || q.list->head == NULL) //Ensures that there is a queue
    return NULL;

  q.list->numOfItems--; //Subtracts the number of items in the queue with values
  Student* returnNode = q.list->head; //Head node to be returned back to user
  q.list->head = q.list->head->nextPtr;
  return returnNode;
}

/*Function has O(1) computational complexity and returns the min priority value
back to the user.*/
Student* returnMin(PQueue q){
  if(q.list == NULL || q.list->head == NULL)
    return NULL;

  return q.list->tail; //Min priority value is held at the tail of the queue
}

/*Function has O(1) computational complexity and returns the max priority value
back to the user.*/
Student* returnMax(PQueue q){
  if(q.list == NULL || q.list->head == NULL)
    return NULL;

  return q.list->head; //Max priority value is held at the head of the queue
}

/*Function frees all previously allocated memories and sets the current queue
to empty. Also frees the "list" pointer in the queue.*/
void freePQueue(PQueue q){
  if(q.list == NULL){ //Checks ot see if a queue is intialized
    printf("No list is initalized.\n");
    return;
  }
  Student* tmpFree = q.list->head;
  Student* tmpHead = q.list->head;
  while(tmpHead != NULL){
    tmpHead = tmpHead->nextPtr;
    free(tmpFree);
    tmpFree = NULL;
    tmpFree = tmpHead;
  }
  free(q.list); //Frees the list pointer
  q.list = NULL;
}

/*Function prints out all the "priority" and "age" values form the head to tail
of the queue.*/
void printPQueue(PQueue q){
  Student* qPrint = q.list->head; //Creates a temporary node to through the queue and print values
  if(qPrint == NULL){ //Checks to see if there are no values in the queue
    printf("There is nothing in this linked list.\n");
    return;
  }

  if(q.list == NULL){ //Checks to see if the queue hasn't been intialized
    printf("The linked list has not been initalized.\n");
    return;
  }

  while(qPrint->nextPtr != NULL){
    printf("%.2f(%d) --> ", qPrint->priority, qPrint->age);
    qPrint = qPrint->nextPtr;
  }
  printf("%.2f(%d) --> End", qPrint->priority, qPrint->age); //Could be put inside but for formating looks cleaner
  puts("");
}
