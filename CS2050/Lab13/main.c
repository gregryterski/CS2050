//Greg Ryterski
//gjr7dz, 18186949
//Lab 13 Main
#include "lab13.h"

int main(void){
  FILE* fptr;
  fptr = fopen("students.csv", "r");
  if(fptr == NULL){
    printf("Nothing is in the file.\n");
    return 0;
  }
  Student** mainArr = readRecord(fptr);
  Student* query = malloc(sizeof(Student));
  query->ID = 73392485;
  printf("Query Value: %d\n", query->ID);
  int isQValue = binarySearch((void**)mainArr, 0, 10000, (void*)query);
  if(isQValue == -1)
    printf("Query value is not in array.\n");

  printf("Query value is in array and its index is %d.\n", isQValue);
  free(query);
  freeArr(mainArr, 10000);
  fclose(fptr);
}
