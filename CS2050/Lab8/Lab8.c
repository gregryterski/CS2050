//Greg Ryterski
//gjr7dz, 18186949
//Lab 8, Group E
#include "Lab8.h"

/*Creates a new node with the value "age" sent to it by the user*/
Student* createNode(int age){
  Student* newStudent = malloc(sizeof(Student));
  if(newStudent == NULL){ //Malloc checking
    return NULL;
  }
  else
  {
    newStudent->age = age;
    newStudent->nextPtr = NULL;
    return newStudent;
  }
}

/*Creates a empty list with no age value*/
Student* initList(){
  return NULL;
}

/*Adds the age value form the user to the head of the list and returns the list
with the newly added head node*/
Student* addToHead(Student* stud, int age){
  Student* headList = malloc(sizeof(Student));
  if(headList == NULL){
    return NULL;
  }

    headList->age = age;
    headList->nextPtr = stud;
    stud = headList;
    return stud;
}

/*Adds the age value from the user to the end of the list
and returns the list*/
Student* addToTail(Student* stud, int age){
  Student* tailList = createNode(age); //Creates a new node with the value of age in it
  if(tailList == NULL){
    return NULL;
  }

  if(stud == NULL){ //If there is nothing in the list existing it adds the node without any moving of the list ptr
    stud = tailList;
  }
  else
  {
    Student* fill = stud;
    while(fill->nextPtr != NULL){ //Has to move the list pointer till it is at the end and pointing to NULL
      fill = fill->nextPtr;
    }
    fill->nextPtr = tailList; //Once it has reached the end it puts the node on the tail
  }
  return stud;
}

/*Prints all values in the linked list from head to tail */
void printList(Student* stud){
  Student* pStud;
  for(pStud = stud; pStud != NULL; pStud = pStud->nextPtr){
    printf("%d ", pStud->age);
  }
	printf("\n");
}

/* This function finds where the first location where the lists age is
equal to the users sent age and returns the location */
int searchAge(Student* stud, int age){
  Student* sChecker = stud;
  int counter=0;
  for(sChecker = stud; sChecker != NULL; sChecker = sChecker->nextPtr){
    if(sChecker->age == age){
      return counter;
      break;
    }
    counter++;
  }
  return -1; //Returns this value if the age searched is not in the list
}

/* Frees all previously allocated memory by the list and sets the list back to NULL*/
Student* freeList(Student* stud){
  Student* filler; //Is used to free individual nodes
  while(stud != NULL){
    filler = stud;
    stud = stud->nextPtr;
    free(filler);
  }
  stud = NULL;
  return stud;
}
