//Greg Ryterski
//gjr7dz, 18186949
//Prelab2
#include<stdio.h>
#include<stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length);
void freeArray(float *array);

int main(void){
  FILE * fptr = fopen("Prelab3.txt", "r");
  int length;
  float *array;
  if(fptr == NULL){
    printf("There is nothing in this file.\n");
    return 0;
  }

  array = readFloatFileIntoArray(fptr, &length);

  if(array == NULL){
    printf("There is no values in the array or malloc failed.\n");
    freeArray(array);
    fclose(fptr);
  }
  else
  {
  for(int i=0; i<length; i++){
    printf("Float %d from file: %.2f\n", i, *(array+i));
  }

  freeArray(array);
  fclose(fptr);
  }
}

float * readFloatFileIntoArray(FILE *fptr, int *length){
  fscanf(fptr, "%d", length);
  float *array= malloc(sizeof(float)**(length)+1);
  *array=(float)*(length);
  array++;
  if(array == NULL){
    printf("Malloc failed.\n");
    return 0;
  }
  else
  {
  for(int i=0; i<(*length); i++){
    fscanf(fptr, " %f", (array + i));
  }
  }
  return (float *)array;
}

void freeArray(float *array){
  for(int i=0; i < *(array-1); i++){
    *(array+i)=0;
  }
  free(array-1);
}
