//Greg Ryterski
//gjr7dz, 18186949
//Prelab 12
#include<stdio.h>
#include<stdlib.h>

typedef struct nodestruct{
  void * item;
  float priority;
  struct nodestruct* lastPtr;
  struct nodestruct* nextPtr;
} Node;

typedef struct queueinfo{
  int size;
  Node *head, *tail;
} QueueInfo;

typedef struct queuelist{
  QueueInfo* ptr;
} PQueue;

PQueue pqInit();
int insertPQ(void * info, float priority, PQueue);
void * deleteMin(PQueue PQueue);
void * deleteMax(PQueue PQueue);
void * returnMin(PQueue PQueue);
void * returnMax(PQueue PQueue);
int getsizePQ(PQueue PQueue);
void printQueue(PQueue PQueue);
void pqFree(PQueue PQueue);

int main(void){
  PQueue pQueue = pqInit();
  int errorcheck = insertPQ((void*)16, 3, pQueue);
  if(errorcheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorcheck = insertPQ((void*)15, 1, pQueue);
  if(errorcheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorcheck = insertPQ((void*)222, 2, pQueue);
  if(errorcheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorcheck = insertPQ((void*)14, 4, pQueue);
  if(errorcheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  errorcheck = insertPQ((void*)13, 5, pQueue);
  if(errorcheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  printf("Least to greatest: ");
  printQueue(pQueue);
  Node* removedMin = deleteMin(pQueue);
  printf("\nLeast to greatest(w Removed Min): ");
  printQueue(pQueue);
  printf("Deleted Node item value: %d\nPriority Number: %.2f\n", (int)removedMin->item, removedMin->priority);

  Node* removedMax = deleteMax(pQueue);
  printf("\nLeast to greatest(w Removed Min & Max): ");
  printQueue(pQueue);
  printf("Deleted Node item value: %d\nPriority Number: %.2f\n", (int)removedMax->item, removedMax->priority);

  Node* returnedMin = returnMin(pQueue);
  Node* returnedMax = returnMax(pQueue);
  int size = getsizePQ(pQueue);
  printf("\nNew Max: %d\nNew Min: %d\nSize: %d\n", (int)returnedMax->item, (int)returnedMin->item, size);
  pqFree(pQueue);
}

PQueue pqInit(){
  PQueue myPQueue;
  myPQueue.ptr = malloc(sizeof(QueueInfo));
  if(myPQueue.ptr == NULL){
    return myPQueue;
  }
  else{
    myPQueue.ptr->head = myPQueue.ptr->tail = NULL;
    myPQueue.ptr->size = 0;
    return myPQueue;
  }
}

int insertPQ(void * info, float priority, PQueue PQueue){
  Node* newNode = malloc(sizeof(Node));
  Node* headNode = PQueue.ptr->head;
  if(newNode == NULL){
    printf("Allocation failed.\n");
    return -1;
  }
  if(PQueue.ptr == NULL){
    printf("There is no Queue initalized.\n");
    return -1;
  }
  else{
    newNode->item = info;
    newNode->priority = priority;
    newNode->nextPtr = NULL;
  }

  PQueue.ptr->size++;
  if(headNode == NULL){
    PQueue.ptr->head = PQueue.ptr->tail = newNode;
  }
  else if(headNode->nextPtr == NULL){
    if(priority<headNode->priority){
      PQueue.ptr->head = newNode;
      newNode->nextPtr = headNode;
      headNode->lastPtr = newNode;
      headNode->nextPtr = NULL;
    }
    else{
      PQueue.ptr->tail = newNode;
      headNode->nextPtr = newNode;
      newNode->lastPtr = headNode;
    }
  }
  else{
    while(headNode->nextPtr != NULL){
      headNode = headNode->nextPtr;
      if(priority<headNode->priority){
        Node* lastNode = headNode->lastPtr;
        lastNode->nextPtr = newNode;
        newNode->lastPtr = lastNode;
        newNode->nextPtr = headNode;
        headNode->lastPtr = newNode;
        break;
      }
    }
    if(priority>headNode->priority){
      PQueue.ptr->tail = newNode;
      headNode->nextPtr = newNode;
      newNode->lastPtr = headNode;
    }
  }
  return 1;
}

void * deleteMin(PQueue PQueue){
  if(PQueue.ptr == NULL){
    return NULL;
  }
  else if(PQueue.ptr->head == NULL){
    return NULL;
  }
  else{
    PQueue.ptr->size--;
    Node* returnNode = PQueue.ptr->tail;
    PQueue.ptr->tail = PQueue.ptr->tail->lastPtr;
    PQueue.ptr->tail->nextPtr = NULL;
    return (void*)returnNode;
  }
}

void * deleteMax(PQueue PQueue){
  if(PQueue.ptr == NULL){
    return NULL;
  }
  else if(PQueue.ptr->head == NULL){
    return NULL;
  }
  else{
    PQueue.ptr->size--;
    Node* returnNode = PQueue.ptr->head;
    PQueue.ptr->head = PQueue.ptr->head->nextPtr;
    return (void*)returnNode;
  }
}

void * returnMin(PQueue PQueue){
  if(PQueue.ptr == NULL){
    return NULL;
  }
  else if(PQueue.ptr->head == NULL){
    return NULL;
  }
  else{
    Node* returnNode = PQueue.ptr->tail;
    return (void*)returnNode;
  }
}

void * returnMax(PQueue PQueue){
  if(PQueue.ptr == NULL){
    return NULL;
  }
  else if(PQueue.ptr->head == NULL){
    return NULL;
  }
  else{
    Node* returnNode = PQueue.ptr->head;
    return (void*)returnNode;
  }
}

int getsizePQ(PQueue PQueue){
  return PQueue.ptr->size;
}

void pqFree(PQueue PQueue){
  if(PQueue.ptr == NULL){
    return;
  }

  Node* tmpFree = PQueue.ptr->head;
  Node* tmpHead = PQueue.ptr->head;
  while(tmpHead != NULL){
    tmpHead = tmpHead->nextPtr;
    free(tmpFree);
    tmpFree = NULL;
    tmpFree = tmpHead;
  }
  free(PQueue.ptr);
  PQueue.ptr = NULL;
}

void printQueue(PQueue PQueue){
    Node* qPrint = PQueue.ptr->head; //Creates a temporary node to through the queue and print values
    if(qPrint == NULL)
      printf("There is nothing in this linked list.\n");

    if(PQueue.ptr == NULL)
      printf("The linked list has not been initalized.\n");

    while(qPrint->nextPtr != NULL){
      printf("%d --> ", (int)qPrint->item);
      qPrint = qPrint->nextPtr;
    }
    printf("%d --> NULL", (int)qPrint->item); //Could be put inside but for formating looks cleaner
    puts("");
}
