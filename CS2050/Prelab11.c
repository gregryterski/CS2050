//Greg Ryterski
//gjr7dz, 18186949
//Prelab 11
#include<stdio.h>
#include<stdlib.h>

typedef struct empstruct{
  int age, ID;
  float salary;
} Employee;

typedef struct nodestruct{
  Employee* key;
  struct nodestruct *next;
} Node;

typedef struct queueinfo{
  int size;
  Node *head, *tail;
} QueueInfo;

typedef struct queuelist{
  QueueInfo *ptr;
} Queue;

Queue initQueue();
int enqueue(Employee* emp, Queue que);
Employee* dequeue(Queue que);
int getQsize(Queue que);
void freeQueue(Queue que);

int main(void){
  int errorCheck = 0;
  Queue headQ = initQueue();
  Employee* emp1 = malloc(sizeof(Employee));
  if(emp1 == NULL)
    return 0;
  emp1->age = 10;
  emp1->ID = 9999;
  emp1->salary = 45000;
  errorCheck = enqueue(emp1, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  Employee* emp2 = malloc(sizeof(Employee));
  if(emp2 == NULL)
    return 0;
  emp2->age = 20;
  emp2->ID = 1111;
  emp2->salary = 90000;
  errorCheck = enqueue(emp2, headQ);
  if(errorCheck == -1){
    printf("There was an error.\n");
    return 0;
  }

  int Qsize = getQsize(headQ);
  printf("Queue size is %d\n", Qsize);

  Employee* oldEmp = dequeue(headQ);
  printf("Employee:\nAge: %d\nID: %d\nSalary: %.2f\n", oldEmp->age, oldEmp->ID, oldEmp->salary);

  Qsize = getQsize(headQ);
  printf("Queue size is %d\n", Qsize);

  freeQueue(headQ);
}

Queue initQueue(){
  Queue que;
  que.ptr = malloc(sizeof(QueueInfo));
  if(que.ptr == NULL){
    printf("Memory couldn't be allocated.\n");
    return que;
  }
  que.ptr->size = 0;
  que.ptr->head = que.ptr->tail = NULL;
  return que;
}

int enqueue(Employee* emp, Queue que){
  Node* input = malloc(sizeof(Node));
  if(input == NULL)
    return -1;
  if(que.ptr->head == NULL){
    que.ptr->size++;
    que.ptr->tail = input;
    input->key = emp;
  }
  else
  {
  que.ptr->size++;
  que.ptr->head = input;
  input->key = emp;
  }

  return 1;
}

Employee* dequeue(Queue que){
  Employee* removedEmp = que.ptr->head->key;
  if(removedEmp == NULL){
    printf("There is nothing in the queue.\n");
    return NULL;
  }
  free(que.ptr->head);
  que.ptr->head = que.ptr->head->next;
  que.ptr->size--;

  return removedEmp;
}

int getQsize(Queue que){
  return que.ptr->size;
}

void freeQueue(Queue que){
  Node* filler;
  while(que.ptr->head != NULL){
    filler = que.ptr->head;
    que.ptr->head = que.ptr->head->next;
    free(filler);
  }
  free(que.ptr);
}
