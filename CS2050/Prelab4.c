//Greg Ryterski
//gjr7dz, 18186949
//Prelab 4
#include<stdio.h>
#include<stdlib.h>
void* createArray(int size, int datatype);
void putNumInArrayint(void *array);
void putNumInArrayfloat(void *array);
void putNumInArraychar(void *array);
int getArraySize(void *array);
void freeArray(void *array);

int main(void){
  int n, size, datatype;
  int *intarray;
  float* floatarray;
  double* doublearray;
  char* chararray;

    printf("Enter the size of array disired: ");
  scanf("%d", &n);
  do{
  printf("Select what data type you want it to be:\n");
  printf("1) Int\n2) Float\n3) Double\n4) Char\n");
  scanf("%d", &datatype);
  if(datatype>4 || datatype<1){
    printf("Enter a datatype in the range 1-4.\n");
  }
  }while(datatype>4 || datatype<1);

  switch (datatype){
    case 1:
      intarray = (int*)createArray(n, sizeof(int));
      putNumInArrayint(intarray);
      size = getArraySize(intarray);
      freeArray(intarray);
      break;
    case 2:
      floatarray = (float*)createArray(n, sizeof(float));
      putNumInArrayfloat(floatarray);
      size = getArraySize(floatarray);
      freeArray(floatarray);
      break;
    case 3:
      doublearray = (double*)createArray(n, sizeof(double));
      putNumInArrayfloat(doublearray);
      size = getArraySize(doublearray);
      freeArray(doublearray);
      break;
    case 4:
      chararray = (char*)createArray(n, sizeof(char));
      putNumInArraychar(chararray);
      size = getArraySize(chararray);
      freeArray(chararray);
      break;
    default:
    size = 0;
    break;
  }

  printf("Size of the array is still %d\n", size);

  return 0;
}

void* createArray(int size, int datatype){
  int *array = (int*)malloc(sizeof(int) + (size * datatype));
  *array = size;
  array++;

  return (void*)(array);
}

void putNumInArrayint(void *array){
  int *arr = (int*)(array);
  for(int i=0; i< *(arr-1); i++){
    arr[i] = ((rand() % 20) + 1);
    printf("Array[%d] = %d\n", i, *(arr+i));
  }
}
void putNumInArrayfloat(void *array){
  int *arra = (int*)(array);
  float *arr = (float*)(array);
  for(int i=0; i< *(arra-1); i++){
    arr[i] = (((rand() % 50) + 1)/3);
    printf("Array[%d] = %.2f\n", i, *(arr+i));
  }
}
void putNumInArraychar(void *array){
  int *arra = (int*)(array);
  char *arr = (char*)(array);
  for(int i=0; i< *(arra-1); i++){
    arr[i] = (65+i);
    printf("Array[%d] = %c\n", i, *(arr+i));
  }
}

int getArraySize(void *array){
  int size = (((int*)array)[-1]);
  return size;
}

void freeArray(void *array){
  free(((int*)array)-1);
  array = NULL;
}
