//Greg Ryterski
//gjr7dz, 18186949
//Lab 15
#include "lab15.h"

/*Function recieves a FILE pointer that is filled with employee data. With this
data it creates an array of "Employee" struct pointers filled with the given
data. It returns the array if successful or NULL if unsuccessful.*/
Employee** readRecord(FILE* fptr){
  if(fptr == NULL) //Checks to see if there is anything in the file
    return NULL;

  int size;
  fscanf(fptr, "%d\n", &size); //Gets the size that is stored at the beginning of the file
  Employee** array = (Employee**)malloc(sizeof(Employee*)*size); //Allocates memory for array
  if(array == NULL)
    return NULL;

  for(int i=0; i<size; i++){
    array[i] = malloc(sizeof(Employee));
    if(array[i] == NULL){ //If malloc fails it frees the previously allocated memory
      for(int k=0; k<i; k++){
        free(array[k]);
      }
      free(array);
      array = NULL;
      return NULL;
    }
    fscanf(fptr, "%d,%f,%d\n", &array[i]->ID, &array[i]->salary, &array[i]->ssn); //Fills the array with the data
  }
  return array;
}

/*Function compares the "ssn" values of the struct pointers. If the a is greater
than b it returns 1 and the opposite returns -1. If they're both equal the
function returns a 0.*/
int comparison(void* a, void* b){
  Employee* newA = (Employee*)a; //Sets them to be "Employee" struct to compare ID values
  Employee* newB = (Employee*)b;

  if(newA->ssn > newB->ssn) return 1;
  if(newA->ssn < newB->ssn) return -1;
  return 0;
}

/*Function recieves the current BST root and an Employee struct pointer that is
being inserted. It creates a new Node with the given Employee information and
recursively inserts the new node into the current BST based on its ssn value in
descending order. It returns the updated BST back to the user or calling function.*/
Node* insertBST(Node* bst, Employee* emp){
  if(bst == NULL){ //If it is the first time being passed into the function
    bst = malloc(sizeof(Node));
    if(bst == NULL)
      return NULL;
    bst->data = emp; //Fills the root to be the given employee struct pointer
    bst->left = NULL;
    bst->right = NULL;
    return bst;
  }
  //Decides if the employee should be stored based on ssn in descending order
  if(comparison(bst->data, emp) == 1){  //Moves to the right branch of the tree
    bst->right = insertBST(bst->right, emp);
  }
  else if(comparison(bst->data, emp) == -1){ //Moves to the left branch of the tree
    bst->left = insertBST(bst->left, emp);
  }
  return bst; //returns the tree once it is placed in the right spot
}

/*Function recieves the current binary search tree and recursively searches the to find an
employee with the given ssn value from the user. If there is no employee with
the given ssn then it returns NULL otherwise it returns the employee struct pointer.*/
Employee* searchBST(Node* bst, int ssn){
  if(bst == NULL)
    return NULL;

  if(ssn < bst->data->ssn){
    return searchBST(bst->right, ssn); //Recursively searches for the the employee sturct
  }
  else if(ssn > bst->data->ssn){
    return searchBST(bst->left, ssn);
  }
  else if(ssn == bst->data->ssn){
    return bst->data;
  }
  return NULL;
}

/*Function recieves the current BST root, then frees all allocated memory for
the whole BST.*/
void deleteTree(Node* bst){
  if(bst == NULL) //Checks to see if tree sent is initalized
    return;

  deleteTree(bst->left);
  deleteTree(bst->right);
  free(bst);
}
