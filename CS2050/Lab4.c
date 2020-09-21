//Greg Ryterski
//gjr7dz, 18186949
//Lab 4, Group E
#include<stdio.h>
#include<stdlib.h>

//Prototypes
void* createArray(int size, int datatype);
int getArraySize(void* array);
void freeArray(void* array);
void storeAve(void* array);

int main(void){
  int arraySize = 10; //size of array
  int returnedSize = 0; //returned size of the array when passed to getArraySize

  double* array = (double*)createArray(arraySize, sizeof(double)); //initializes and creates an array of type double
  returnedSize = getArraySize(array); //returns the size of the function, which is stored in array[-2]

  for(int i=0; i< returnedSize+1; i++){ //adds numbers into the array within till it is full
    array[i] = ((rand() % 50)/3 + 1);
  }

  storeAve(array);
  array = &(array[1]); //increments the address to be the location of the first element

  printf("Elements in array are: "); //prints the elements in the array of type double
  for(int i=0; i<returnedSize; i++){
    printf("%.2f, ", array[i]);
  }
  printf("\n\n");
  printf("Array size is %d, and the average value of all elements is %.2f\n", returnedSize, array[-1]); //prints the array size and the average value that was hidden

  freeArray(array); //sets the array to NULL and deallocates memory for it
}

//creates an array of type double and allocates memory for the size+2 to allow storage of size & average under array[0]
void* createArray(int size, int datatype){
  double *array = (double*)malloc((sizeof(double)*2) + (size * datatype));
  *array = size;  //sets the size = array[0] then hides it by moving the array +1
  array++;
  return (void*)(array); //returns the array as a void* to be compatible with any type
}

//functions uses the hiddden array size and returns it back to the main function
int getArraySize(void* array){
  double size = (((double*)(array))[-1]);
  return size;
}

//computes the average of the values stored within the array by totaling them and dividing by the hidden size
//hides the size of the average value in the location of array[-1]
void storeAve(void* array){
  double *arr = (double*)(array); //for convinence create a new "fake" array that has the values of array
  double totalNum =0;
  double avgValue = 0;
  int size = arr[-1]; //sets size based off the hidden size in the sent array

  for(int i=1; i< size; i++){
    totalNum += arr[i];
  }
  avgValue = totalNum/size; //computes the average by dividing the total numbers, in the array, over the size
  *arr = avgValue; //stores the average in array[0] where it can be hidden
}

//deallocates the array (which is the size of it with the additonal 2 spaces back that are hidden)
//also sets the array's address to NULL and cleans the array
void freeArray(void *array){
  free(((double*)array)-2);
  array = NULL;
}
