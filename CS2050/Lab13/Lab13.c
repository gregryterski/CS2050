//Greg Ryterski
//gjr7dz, 18186949
//Lab 13
#include "lab13.h"

/*Function recieves a FILE pointer and creates an array of "Student" struct
pointers. The array is filled with the provided information from the file.
It returns the array if successful or NULL if failed.*/
Student** readRecord(FILE* fptr){
  if(fptr == NULL) //If there is no file provided the function returns NULL
    return NULL;

  int size;
  fscanf(fptr, "%d\n", &size); //Obtains the file size at the beginning of the file
  Student** array = (Student**)malloc(sizeof(Student*)*size);
  if(array == NULL){
    printf("Malloc has failed.\n");
    return NULL;
  }
  for(int i=0; i<size; i++){
    array[i] = malloc(sizeof(Student)); //Allocates memory for the "Student" structs
    if(array[i] == NULL){ //Frees the memory if malloc fails at any point
      printf("Allocation of memory for sturcts has failed.\n");
      for(int k=0; k<i; k++){
        free(array[k]);
      }
      free(array);
      array = NULL;
      return NULL;
    }
  }

  for(int j=0; j<size; j++){
    fscanf(fptr, "%d,%d\n", &array[j]->age, &array[j]->ID); //Inputs the provided info in the array
  }
  return array;
}

/*Function compares the "ID" values of the struct pointers. If the a is greater
than b it returns 1 and the opposite returns -1. If they're both equal the
function returns a 0.*/
int comparison(void* a, void* b){
  Student* newA = (Student*)a; //Sets them to be "Student" struct to compare ID values
  Student* newB = (Student*)b;

  if(newA->ID > newB->ID) return 1;
  if(newA->ID < newB->ID) return -1;
  return 0;
}

/*Function recieves a sorted struct pointer array (sorted with "ID" values in
decending order), two integers indicating the boundaries, and a query "Student"
struct pointer. The function recursively searchs for the query structs "ID" value
and returns the index if the "ID" exists in the array. It returns a -1 if there
is no array or if it is out of boundaries.*/
int binarySearch(void** orderedArray, int first, int last, void* query){
  if(orderedArray == NULL)
    return -1;

  if(first>last)
    return -1;

  int mid = (first+last)/2; //Gets the middle index value inbetween the boundaries

  if(comparison(query, (void*)orderedArray[mid]) == 1) //Compares the query and arrays "ID" values
    return binarySearch(orderedArray, first, mid-1, query); //Reloops to the top of the search with a new last value

  if(comparison(query, (void*)orderedArray[mid]) == -1)
    return binarySearch(orderedArray, mid+1, last, query);

  if(comparison(query, (void*)orderedArray[mid]) == 0)
    return mid; //returns the index value if the query value is in the array

  return mid; //Returns True or mid, not really necessary but required for type "int" function
}

/*This function recieves the current pointer array, and its size, then frees
all previously allocated memories*/
void freeArr(Student** array, int size){
  if(array == NULL) //Returns if there is no array initialized
    return;

  for(int i=0; i<size; i++){ //Frees in individual struct pointers
    free(array[i]);
  }
  free(array); //Frees the array
  array = NULL;
}
