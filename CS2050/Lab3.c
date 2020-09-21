//Greg Ryterski
//gjr7dz, 18186949
//Group E, Lab 3
#include<stdio.h>
#include<stdlib.h>

int * readIntAgeIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge);
void findMinMax(int* arr, int size, int* minAge, int* maxAge);
void freeIntArray(int**arrPtr);

int main(void){
  int totalemployees;
  float averageAge;
  int *array;
  int minAge=100;
  int maxAge=0;
  FILE *fptr = fopen("employeeAge.txt", "r");
  if(fptr == NULL){
    printf("There is nothing in this file or something went wrong.\n");
  }
  else
  {
  array = readIntAgeIntoArray(fptr, &totalemployees, &averageAge);

  findMinMax(array, totalemployees, &minAge, &maxAge);
  printf("There are %d total employees, the average age is %.2f, the max age is %d, the min age is %d\n", totalemployees, averageAge, maxAge, minAge);

  freeIntArray(&array);
  if(array == NULL){
    printf("The arrays is freed and set to NULL\n");
  }

  fclose(fptr);
  }
}

int* readIntAgeIntoArray(FILE *fp, int* totalNumOfEmployee, float* averageAge){
  fscanf(fp, "%d", totalNumOfEmployee);
  int totalAge = 0;
  int *array = malloc(sizeof(int)* (1+(*(totalNumOfEmployee))));
  *array = *(totalNumOfEmployee);
  array++;

  if(array == NULL){
    printf("Malloc has failed.\n");
    return 0;
  }
  else
  {
  for(int i=0; i<*(totalNumOfEmployee); i++){
    fscanf(fp, "\n%d", &array[i]);
    totalAge += array[i];
  }
  *(averageAge) = totalAge/ *(totalNumOfEmployee);

  return array;
  }
}

void findMinMax(int* array, int size, int *minAge, int* maxAge){
  for(int i=0; i<size; i++){
    if(array[i] > *(maxAge)){
      *(maxAge) = *(array+i);
    }
    if(array[i] < *(minAge)){
      *(minAge) = *(array+i);
    }
  }
}

void freeIntArray(int**arrPtr){
  free(*arrPtr-1);
  *arrPtr = NULL;
}
