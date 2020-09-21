//Greg Ryterski
//gjr7dz, 18186949
//Prelab 13
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int ssn, age;
  float salary;
} Employee;

int compare(void *a, void *b);
int member(int orderedArray[], int first, int last, int query);

int main(void){
  int a[] = {2, 16, 201, 451};
  int b[] = {16};
  int returnComp = compare(a, b);
  if(returnComp == 1)
    printf("A is greater than B.\n");

  if(returnComp == -1)
    printf("A is less than B.\n");

  if(returnComp == 0)
    printf("A is equal to B.\n");

  int returnMem = member(a, 0, 4, 16);
  if(returnMem == 1)
    printf("Query value is in array.\n");

  if(returnMem == -1)
    printf("Query value is not in array.\n");

}

int compare(void *a, void *b){
  int* aa = (int*)a;
  int* bb = (int*)b;

  if(*aa > *bb) return 1;
  if(*aa < *bb) return -1;
  return 0;
}

int member(int orderedArray[], int first, int last, int query){
  if(first > last)
    return -1;

  int mid = (first+last)/2;
  int arrayNum = orderedArray[mid];

  if(compare(&query, &arrayNum) == 1)
    return  member(orderedArray, mid+1, last, query);

  if(compare(&query, &arrayNum) == -1)
    return member(orderedArray, first, mid-1, query);

  if(compare(&query, &arrayNum) == 0)
    return 1;

  return 1;
}
