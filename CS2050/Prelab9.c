//Greg Ryterski
//gjr7dz, 18186949
//Prelab 9
#include<stdio.h>
#include<stdlib.h>

typedef struct nodestruct{ //struct that holds an int and pointer
	int item;
	struct nodestruct *next;
 } Node;

typedef struct liststruct{
	int size;
	Node * head, * tail;
	} List;

List * createList();
void freeList(List *list);
int getListLength(List *list);
int insertAtHead(int val, List *list);
int insertAtTail(int val, List *list );
List * copyList(List *list);
void printList(List *list);

int main(void){
  List *head = createList();
  int errorCount = 0;
  errorCount = errorCount + insertAtHead(25, head);
  errorCount = errorCount + insertAtTail(25, head);
  errorCount = errorCount + insertAtHead(30, head);
  errorCount = errorCount + insertAtTail(20, head);
  int length = getListLength(head);
  printf("\nLength of list is: %d\n", length);
  printList(head);
  List *tail = copyList(head);
  int length2 = getListLength(tail);
  printf("\nLength of list is: %d\n", length2);
  printList(tail);
  freeList(head);
  freeList(tail);
  printf("Number of Errors: %d\n", errorCount);
  if(head == NULL)
    printf("Memory is deallocated.\n");
}

void printList(List* list){
  Node *pNode = list->head->next;
	if(pNode == NULL)
		printf("There is nothing in this linked list.\n");

  while(pNode != NULL){
		printf("%d ", pNode->item);
		pNode = pNode->next;
	}
	printf("\n");
}

List * createList(){
  List *cList = malloc(sizeof(List));
	if(cList == NULL){
		printf("Malloc has failed.\n");
		return NULL;
	}
	cList->size = 0;

	Node *newNode = malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Malloc has failed.\n");
		return NULL;
	}

	newNode->next = NULL;
	newNode->item = 111111;
	cList->head = newNode;
	cList->tail = newNode;

	return cList;
}

int getListLength(List *list){
  return list->size;
}

int insertAtHead(int val, List *list){
  Node* headNode = malloc(sizeof(List));
  if(headNode == NULL)
    return 1;

	list->size++;
  headNode->item = val;

  headNode->next = list->head->next;
	list->head->next = headNode;
	if(headNode->next == NULL)
		list->tail = headNode;

  return 0;
}

int insertAtTail(int val, List *list){
  Node* tailNode = malloc(sizeof(List));
  if(tailNode == NULL)
    return 1;

	list->size++;
  tailNode->item = val;

  tailNode->next = NULL;
	list->tail->next = tailNode;
	list->tail = tailNode;

	return 0;
}


List * copyList(List * list){
  if(list == NULL)
    return NULL;
	List *newList = createList();
	if(newList == NULL)
		return NULL;
	int item;
	Node *holder = list->head->next;
	for(int i=0; i<getListLength(list); i++){
		item = holder->item;
		holder = holder->next;
		insertAtTail(item, newList);
	}

  return newList;
}

void freeList(List* list){
  Node* filler;
  while(list->head != NULL){
    filler = list->head;
    list->head = list->head->next;
    free(filler);
  }
	free(list);
}
