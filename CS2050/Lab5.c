//Greg Ryterski
//gjr7dz, 18186949
//Lab 5, Group E
#include<stdio.h>
#include<stdlib.h>

void** create2DArray(int numRows, int numCols, int elemSize);
float getRowSize(void** table);
float getColSize(void** table, int rowNo);
void printTable(void** table);
void freeTable(void** table);

//creating a struct to hold the dimensions of the table
typedef struct{
  int numRows, numCols;
} TableDim;

int main(void){
  TableDim Table1;
  Table1.numRows = 6;
  Table1.numCols = 3;
  float** table = (float**)create2DArray(Table1.numRows, Table1.numCols, sizeof(float)); //creates a 2D array of type float
  int** table2 = (int**)create2DArray(Table1.numRows, Table1.numCols, sizeof(int)); //creates a 2D array of type int
  int rowSize2 = (int)getRowSize((void**)table2); //gets the row size of the type int 2d array
  float rowSize = getRowSize((void**)table);  //gets the row size of the type float 2d array
  printf("Row size float = %.2f, Row size int = %d\n", rowSize, rowSize2); //prints the sizes
  float colSize = getColSize((void**)table, 2); //gets the column size for the type float 2d array
  int colSize2 = (int)getColSize((void**)table2, 2); //gets the column size for the type int 2d array
  if(colSize==-1 ||colSize2 == -1){ //bounds checking to see that neither of the column sizes are outside of the rows allocated
    printf("Referencing outside row bounds.\n");
    return 0;
  }
  printf("Column size float = %.2f, Column size int = %d\n", colSize, colSize2); //prints the column sizes
  int countNum = 0;
  for(int i=0; i<rowSize; i++){
    for(int k=0; k<colSize; k++){
      table2[i][k] = countNum;
      countNum++;
    }
  }
  printTable((void**)table2); //Prints the table of values of type int
  freeTable((void**)table); //frees the float 2d array
  freeTable((void**)table2); //frees the int 2d array
}
/* This function creates a 2D array of any type that is sent to it by the user and stores the number of rows
at [-1][-1] on the table and then proceeds to store the number of columns in each row before the first
"visible" element is shown, which hides the num of columns */
void** create2DArray(int numRows, int numCols, int elemSize){
  float** array = (float**)malloc(numRows * sizeof(float*) + (2*elemSize));
  if(array == NULL){
    printf("Malloc has failed.\n");
    return NULL;
  }

  for(int i=0; i<numRows+1; i++){
    array[i] = ((float*)malloc(numCols*elemSize+elemSize));
  }

  if(*array == NULL){
    printf("Malloc has failed.\n");
    return 0;
  }
  *(array-1) = numRows;
  array++;

  for(int k=0; k<numRows; k++){
    array[k][0] = numCols;
    array[k]++;
  }

  return (void**)array;
}
/* The function recieves the 2D array of any type and returns the row size based off the value
that is stored in [-1][-1], which is where the row size is located when created*/
float getRowSize(void** table){
  float** rowTable = (float**)table;
  float rowSize = *((float*)rowTable-1);
  return rowSize;
}

/* The function first gets the row size to check whether the row number (rowNo) sent to it is
within range of the allocated row space and is a row on the table. If it is it grabs the size of
the columns by peaking 1 behind the first element in the row and returning this value */
float getColSize(void** table, int rowNo){
  float rowSize = getRowSize(table);
  if(rowSize < rowNo || 0 > rowNo){
    printf("Row doesn't exist.\n");
    return -1;
  }
  float** colTable = (float**)table;
  float colSize = colTable[rowNo][-1];

  return colSize;
}

/* This function initializes values into the 2D array and prints the values*/
void printTable(void** table){
  int** table1 = (int**)table;
  float rowSize = getRowSize(table);
  float columns = 0;
  for(int i=0; i<rowSize; i++){
    columns = getColSize(table, i);
    if(columns == -1){
      printf("Row sent is not in bounds.\n");
    }
    for(int k=0; k<columns; k++){
      printf("Table[%d][%d] = %d\n", i, k, table1[i][k]);
    }
  }
}
/*This function frees the array allocated + the hidden elements with "-1" and sets it equal to NULL*/
void freeTable(void** table){
  float** fTable = (float**)table;
  float rowSize = getRowSize(table);
  for(int i=0; i<rowSize; i++){
    free(fTable[i]-1);
  }
  free((float**)table-1);
  table = NULL;
}
