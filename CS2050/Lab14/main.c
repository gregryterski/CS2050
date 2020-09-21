//Greg Ryterski
//gjr7dz, 18186949
//Lab 14 Main
#include "lab14.h"

int main(void){
  FILE* fptr;
  fptr = fopen("students.csv", "r");
  if(fptr == NULL){
    printf("Nothing is in the file.\n");
    return 0;
  }
  Student** mainArr = readRecord(fptr);
  StudentDB studDB = createDatabase(mainArr, 10000);
  printf("Data size: %d\n", studDB.sizeOfDB);
  for(int i=0; i<studDB.sizeOfDB; i++){
    printf("Age: %d ID: %d\n", mainArr[i]->age, mainArr[i]->ID);
  }
  printf("All Students!\n");
  Student* foundID = findStudentByID(studDB, 8688211);
  if(foundID != NULL){
  printf("Found Student ID:\nAge: %d\nID: %d\n", foundID->age, foundID->ID);
  }
  else{
    printf("There is no student found with the searched ID.\n");
  }
  freeDatabase(studDB);
}
