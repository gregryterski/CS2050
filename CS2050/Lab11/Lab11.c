//Greg Ryterski
//gjr7dz, 18186949
//Lab 11
#include "lab11.h"

/*This function initializes an empty queue and sets all of the inner members
located in StudentList to 0. It also points the head and tail to NULL then returns
the queue back to the user.*/
Queue initQueue(){
  Queue q;
  q.list = malloc(sizeof(StudentList));
  if(q.list == NULL){
    printf("Memory allocation has failed.\n"); //If malloc has failed it will print a message
    return q; //Returns essentially NULL back to the user since malloc has failed
  }
  q.list->numOfItems = 0;
  q.list->numOfOdd = 0;
  q.list->numOfEven = 0;
  q.list->head = q.list->tail = NULL;

  return q;
}

/*Function recieves a student's age and adds them to the queue. It increases the
number of items in the queue and also checks if there age is even or odd. If
there age is even or odd it increments the number of students whos names are
even or odd. Returns a 1 if successful or -1 if it has failed.*/
int enQueue(int age, Queue q){
  Student* newStud = malloc(sizeof(Student));
  if(newStud == NULL || q.list == NULL) //Checks for errors in malloc or no initalized list
    return -1;

  newStud->age = age; //Sets the new Nodes age to the age from the user
  newStud->nextPtr = NULL;
  q.list->numOfItems++;
  if(age % 2 == 0){ //Checks if there is a remainer and if not then it is even
    q.list->numOfEven++;
  }
  else{
    q.list->numOfOdd++;
  }

  if(q.list->head == NULL){ //If there is nothing already in the list the new node is the head and tail
    q.list->tail = q.list->head = newStud;
  }
  else{
    q.list->tail->nextPtr = newStud;
    q.list->tail = newStud;
  }

  return 1;
}

/*The function removes the earliest student added to the queue. It also decrements
the number of items, and even or odd, values stored in the queue. Returns the
pointer to the dequeued node.*/
Student* deQueue(Queue q){
  Student* returnTemp = q.list->head; //Pointer to the node that is being dequeued
  if(returnTemp == NULL || q.list == NULL)
    return NULL;

  int age = q.list->tail->age;
  q.list->numOfItems--;
  if(age % 2 == 0){
    q.list->numOfEven--;
  }
  else {
    q.list->numOfOdd--;
  }

  if(q.list->head->nextPtr == NULL){ //Checks to see if the list only has 1 student in it
    q.list->head = q.list->tail = NULL; //Clears the queue
    return returnTemp;
  }

  q.list->head = q.list->head->nextPtr; //Sets the new head to be the next node over

  return returnTemp;
}

/*Function gets the size of the queue and returns it to the user.*/
int getQsize(Queue q){
  return q.list->numOfItems; //Value is stored in the queue
}

/*Function gets the number of evens in the queue and returns it to the user.*/
int getNumOfEven(Queue q){
  return q.list->numOfEven;
}

/*Function prints all of the student's ages that are in the queue.*/
void printQueue(Queue q){
  Student* qPrint = q.list->head; //Creates a temporary node to through the queue and print values
  if(qPrint == NULL)
    printf("There is nothing in this linked list.\n");

  if(q.list == NULL)
    printf("The linked list has not been initalized.\n");

  while(qPrint->nextPtr != NULL){
    printf("%d --> ", qPrint->age);
    qPrint = qPrint->nextPtr;
  }
  printf("%d --> NULL", qPrint->age); //Could be put inside but for formating looks cleaner
  puts("");
}

/*Function frees all previously allocated memory and sets the current queue to empty*/
void emptyQueue(Queue q){
  Student* tmpFree = q.list->head; //Used to free nodes in the queue
  Student* tmpHead = q.list->head; //Used to increment through the queue
  while(tmpHead != NULL){
    tmpHead = tmpHead->nextPtr;
    free(tmpFree);
    tmpFree = NULL;
    tmpFree = tmpHead;
  }
  free(q.list); //Frees the list pointer in the queue
}
