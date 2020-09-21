#include<stdio.h>
#include<stdlib.h>
void getArraysize(int *array);
int main(void){
  int *array = malloc(8*sizeof(int));
  array[0] = 7;
  array++;
  getArraysize(array);
}

void getArraysize(int *array){
  printf("Array is %d.\n", array[-1]);
}
