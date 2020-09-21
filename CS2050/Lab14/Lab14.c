//Greg Ryterski
//gjr7dz, 18186949
//Lab 14
#include "lab14.h"

/*Function recieves a FILE pointer and creates an array of "Student" struct
pointers. It fills the array with the provided info. Returns the array if
successful or NULL if there was an error.*/
Student** readRecord(FILE* fptr){
  if(fptr == NULL)
    return NULL;

  int size;
  fscanf(fptr, "%d\n", &size);
  Student** array = (Student**)malloc(sizeof(Student*)*size); //Allocates memory for the array
  if(array == NULL){
    printf("Malloc has failed.\n");
    return NULL;
  }
  for(int i=0; i<size; i++){
    array[i] = malloc(sizeof(Student));
    if(array[i] == NULL){ //If malloc fails then it frees previously allocated memory
      printf("Allocation of memory for structs has failed.\n");
      for(int k=0; k<i; k++){
        free(array[k]);
      }
      free(array);
      array = NULL;
      return NULL;
    }
  }

  for(int j=0; j<size; j++){
    fscanf(fptr, "%d,%d\n", &array[j]->age, &array[j]->ID); //Inputs the info into the array
  }
  return array;
}

/*Function recieves an array "Student" of student pointers and the size of the
array. It then creates a database for the students and stores the size as well.
It sorts the array of "Student" pointers based on "ID" in descending order. Insertion
sort is used to sort this. Assume a size has to be given.*/
StudentDB createDatabase(Student** array,int size){
  if(array == NULL){
    printf("Array is uninitalized.\n");
  }

  StudentDB studDB;
  studDB.sizeOfDB = size; //Stores the size in the database
  Student* temp = NULL;
  int j;
  for(int i=0; i<size; i++){ //Insertion sort in descending order
    j = i;
    while(j > 0 && array[j]->ID > array[j-1]->ID){
      temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
      j--;
    }
  }
  studDB.array = array;
  return studDB;
}

/*Function recieves a "StudentDB" struct and query value. It recursivley searches
for any "Student" that has an "ID" member equal to the query value. It returns a
pointer to this "Student" if "Student" exists. If there is no students with the
given query/id value then it returns NULL. This function has O(log(N)) complexity.*/
Student* findStudentByID(StudentDB studDB, int id){
  if(studDB.array == NULL)
    return NULL;

  Student** stud = studDB.array;
  int mid = studDB.sizeOfDB/2; //Gets the mid value in the current array
  if(studDB.sizeOfDB <= 0) //Checks if empty, through the list already
    return NULL;

  if(id > stud[mid]->ID){ //If the ID is greater than, send back the lower half
    studDB.array = &stud[0];
    studDB.sizeOfDB = mid - 1;
    return findStudentByID(studDB, id);
  }
  else if(id < stud[mid]->ID){ //If the ID is less than, send back the upper half
    studDB.array = &stud[mid+1];
    studDB.sizeOfDB = studDB.sizeOfDB - mid + 1;
    return findStudentByID(studDB, id);
  }
  else{
    return stud[mid]; //If the ID's are the same send back the "Student" pointer
  }
  return NULL;
}

/*Function recieves the current "StudentDB," then frees all previously allocated
memories.*/
void freeDatabase(StudentDB studDB){
  if(studDB.array == NULL)
    return;

  Student** tmpFree = studDB.array;
  for(int i=0; i<studDB.sizeOfDB; i++){
    free(tmpFree[i]);
  }
  free(tmpFree); //Frees the pointer to the "Student" structs
  tmpFree = NULL;
}
