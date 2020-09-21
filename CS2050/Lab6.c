//Greg Ryterski
//gjr7dz, 18186949
//Lab 6, Group E
#include<stdio.h>
#include<stdlib.h>

//Structure that contains the initialization of variables
typedef struct {
  int empID, age, ssn;
  float salary;
} Record;

//Prototypes
Record* readRecordFile(FILE *fptr);
int getSize(Record* file);
Record* getEmpByAge(Record* file, int age);
void adjustSalaries(Record* file, int age, float multnumber);
void freeRecordArray(Record* file);

int main(void){
  FILE *fptr = fopen("employee.csv", "r");
  if(fptr == NULL){
    printf("There is nothing in this file or it doesn't exist.\n");
    return 0;
  }

  Record* files = readRecordFile(fptr);
  if(files == NULL) return 0;
  int size = getSize(files);
  printf("The file size is %d.\n", size);
  Record* employee = getEmpByAge(files, 19);
  if(employee == NULL) return 0;
  printf("The first employee with the age of 19:\nAge: %d\nEmployeeID: %d\nSSN: %d\nSalary: %.2f\n", employee->age, employee->empID, employee->ssn, employee->salary);
  adjustSalaries(files, 19, 15.25);
  printf("Adjusted Salary: %.2f\n", employee->salary);
  freeRecordArray(files);
}

/*This function recieves a file poniter and scans the first integer value, which
declares the size of the employees. Once the size is determined it allocates memory
for each employee and an additional int value that is stored at the beggining of
the array. If the memory has failed to be allocated it returns NULL to the user. It then
hides the size at the beginning of the array and shifts. For each employee it stores
their salary, age, ID, and SSN. Finally returns this array of structs back to the user.*/
Record* readRecordFile(FILE *fptr){
  int size=0;
  fscanf(fptr, "%d\n", &size);

  Record* fileArray = malloc((sizeof(Record)*size)+sizeof(int));
  if(fileArray == NULL){
    printf("Malloc has failed.\n");
    fclose(fptr);
    return NULL;
  }

  *((int*)fileArray) = size;
  fileArray = (Record*)((int*)fileArray+1);

  for(int k=0; k<size; k++){
    fscanf(fptr, "%f,%d,%d,%d\n", &(fileArray)[k].salary, &(fileArray)[k].age, &(fileArray)[k].empID, &(fileArray)[k].ssn);
  }

  return fileArray;
}

int getSize(Record* file){
  int size = *((int*)file-1);
  return size;
}

/*This function recieves a array of structs with an integer value of an age.
If it is a valid age that matches with at least one of the stored ages it
returns the first employees information with that age. And if there is no employee
matching that age it returns NULL back to the user meaning there is no employees with
that age.*/
Record* getEmpByAge(Record* file, int age){
  int fileSize = getSize(file);
  Record* employee = NULL;
  for(int i=0; i<fileSize; i++){
    if(file[i].age == age){
      employee = &file[i];
      break;
    }
  }

  if(employee == NULL){
    printf("There is no employee with this age.\n");
    return NULL;
  }

  return employee;
}

/*This function recieves a file, an age, and a number to multiply the salary.
If the employee has an age matching the one sent to this function their salary
will be multiplied by the "multnumber" value and be changed till the program is
exited.*/
void adjustSalaries(Record* file, int age, float multnumber){
  int fileSize = getSize(file);
  for(int i=0; i<fileSize; i++){
    if((file[i].age) == age){
      file[i].salary *= multnumber;
    }
  }
}

/*This functions recieves the array of structs and frees the memory of each struct
and the additional +1 of the hidden integer value of the size*/
void freeRecordArray(Record* file){
  free((int*)file-1);
}
