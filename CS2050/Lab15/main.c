//Greg Ryterski
//gjr7dz, 18186949
//Lab 15 Main
#include "lab15.h"

int main(void){
  FILE* fptr;
  fptr = fopen("employee.csv", "r");
  if(fptr == NULL){
    printf("Nothing is in the file.\n");
    return 0;
  }
  Employee** mainArr = readRecord(fptr);
  Node* bst = NULL;
  for(int i=0; i<10000; i++){
    bst = insertBST(bst, mainArr[i]);
  }
  Employee* foundEmp = searchBST(bst, 40847600);
  if(foundEmp == NULL){
    printf("There is no employee with that ssn.\n");
    return 0;
  }
  printf("FoundEmp:\nID: %d\nSalary: %f\nSSN: %d\n", foundEmp->ID, foundEmp->salary, foundEmp->ssn);
  deleteTree(bst);
}
