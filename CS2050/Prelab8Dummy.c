//Greg Ryterski
//gjr7dz, 18186949
//Prelab 8
#include<stdio.h>
#include<stdlib.h>

typedef struct liststruct{ //struct that holds an int and pointer
	int item;
	struct liststruct *next;
	}List;

List* initIntegerList();
int insertAtHead(int k, List* list);
int insertAtTail(int k, List* list);
void printList(List* list);
void freeList(List** list);

int main(void){
  List* headList;
  headList = initIntegerList();
  int errorCount = 0;
  int headNum, tailNum;

  printf("Enter a number to insert at Head: ");
  scanf("%d", &headNum);
  errorCount = insertAtHead(headNum, headList);
  printf("Enter a number to insert at Tail: ");
  scanf("%d", &tailNum);
  errorCount = errorCount + insertAtTail(tailNum, headList);
	printf("List: ");
  printList(headList);
  printf("Enter a number to insert at Head: ");
  scanf("%d", &headNum);
  errorCount = errorCount + insertAtHead(headNum, headList);
  printf("Enter a number to insert at Tail: ");
  scanf("%d", &tailNum);
	errorCount = errorCount + insertAtTail(tailNum, headList);
  printf("\nNew list:\n");
  printList(headList);
	printf("Number of mallocs failed: %d\n", errorCount);
  freeList(&headList);
	if(headList == NULL){
		printf("Memory is deallocated.\n");
	}
}

List* initIntegerList(){
	List* dummy = malloc(sizeof(List));
	dummy->item = 1000;
	dummy->next = NULL;
  return dummy;
}

int insertAtHead(int k, List* list){
  List* headList = malloc(sizeof(List));
  if(headList == NULL){
    return(-1);
  }

    headList->item = k;
    headList->next = (list)->next;
    (list)->next = headList;
    return(0);
}

int insertAtTail(int k, List* list){
  List* tailList = malloc(sizeof(List));
  if(tailList == NULL){
    return(-1);
  }

  tailList->item = k;

  while((list)->next != NULL){
		list = (list)->next;
	}

	tailList->next = (list)->next;
	(list)->next = tailList;

  return(0);
}

void printList(List* list){
  List* pList;
  for(pList = list->next; pList != NULL; pList = pList->next){
    printf("%d ", pList->item);
  }
	printf("\n");
}

void freeList(List** list){
  List* filler;
  while((*list) != NULL){
    filler = (*list);
    (*list) = (*list)->next;
    free(filler);
  }
	*list = NULL;
}
