//Greg Ryterski
//gjr7dz, 18186949
//Prelab 5
#include<stdio.h>
#include<stdlib.h>

void** createTable(int numRows, int numCols, int elemSize);
int getRowSize(void* array);
int getColSize(void* array);
void freeTable(void** array);

typedef struct {
  int numberOfRows, numberOfColumns;
} TableDimensions;

int main(void){
  TableDimensions Table1;
  Table1.numberOfRows = 5;
  Table1.numberOfColumns = 6;
  int** table = (int**)createTable(Table1.numberOfRows, Table1.numberOfColumns, sizeof(int));
  int rowSize = getRowSize(table);
  int colSize = getColSize(table);
  printf("rowSize = %d, colSize = %d\n", rowSize, colSize);
  printf("Rows = %d, Colms = %d\n", table[-2][0], table[-1][0]);
  for(int i=0; i<rowSize; i++){
    for(int j=0; j<colSize; j++){
      table[i][j] = i+j;
      printf("Array[%d][%d] = %d\n", i, j, table[i][j]);
    }
  }
  freeTable((void**)table);
}

void** createTable(int numRows, int numCols, int elemSize){
  int** array = (int**)malloc((numRows+2) * sizeof(int*) + (2*elemSize));

  for(int i=0; i<(numRows+2); i++){
    array[i] = ((int*)malloc(numCols*elemSize));
  }

  (*array)[0] = numRows;
  array++;
  (*array)[0] = numCols;
  array++;

  printf("Array[0][0] = %d, array[0][1] = %d\n", array[-2][0], array[-1][0]);

  printf("Complete.\n");

  return (void**)array;
}

int getRowSize(void* array){
  int** arr = array;
  int rowSize = arr[-2][0];
  return (rowSize);
}

int getColSize(void* array){
  int** arr = array;
  int colSize = arr[-1][0];
  return (colSize);
}

void freeTable(void** array){
  int rowSize = getRowSize(array);
  for(int i=0; i<rowSize+1; i++){
        free(((int**)array)[i]);
        ((int**)array)[i] = 0;
  }
  free((int**)array-1);
  array = NULL;
  if(array == NULL){
    printf("Memory was freed.\n");
  }
}
