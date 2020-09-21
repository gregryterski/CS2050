//Greg Ryterski
//gjr7dz, 18186949
//Prelab 14
#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int SSN, ID;
  float salary;
} Employee;

typedef struct{
  Employee** empSSN;
  Employee** empID;
  int size;
} empDatabase;

empDatabase createSearchableEmployeeDB(Employee** emp, int size);
Employee * findEmpBySSN(int SSN, empDatabase data);
Employee * findEmpByID(int ID, empDatabase data);
void freeEmpDatabase(empDatabase data);
void printDatabase(empDatabase data);

int main(void){
  int size = 10;
  Employee** emp = malloc(sizeof(Employee*)*size);
  for(int i=0; i<size; i++){
    emp[i] = malloc(sizeof(Employee));
    if(emp[i] == NULL){
      for(int k=0; k<i; k++){
        free(emp[k]);
      }
      free(emp);
      emp = NULL;
      return 0;
    }
  }

  empDatabase empDB = createSearchableEmployeeDB(emp, size);
  Employee* empSSN = findEmpBySSN(1001, empDB);
  if(empSSN == NULL){
    printf("Employee based on SSN not found.\n");
    return 0;
  }
  Employee* empID = findEmpByID(4998, empDB);
  if(empID == NULL){
    printf("Employee not based on ID found.\n");
    return 0;
  }
  printDatabase(empDB);
  printf("Employee Found Based Off SSN\nSSN: %d\nID: %d\n", empSSN->SSN, empSSN->ID);
  printf("Employee Found Based Off ID\nSSN: %d\nID: %d\n", empID->SSN, empID->ID);
}

empDatabase createSearchableEmployeeDB(Employee** emp, int size){
  empDatabase empDB;
  empDB.size = size;

  for(int i=0; i<size; i++){
    emp[i]->SSN = i + 1000;
    emp[i]->ID = 5000 - i;
  }

  Employee** empSortedSSN = emp;
  Employee** empSortedID = emp;
  int z, temp, i;
  do{
    z = -1;
    for(i=0; i<size-1; i++){
      if(empSortedSSN[i]->SSN > empSortedSSN[i+1]->SSN){
        temp = empSortedSSN[i]->SSN;
        empSortedSSN[i]->SSN = empSortedSSN[i+1]->SSN;
        empSortedSSN[i+1]->SSN = temp;
        z = 1;
      }
      if(empSortedID[i]->ID > empSortedID[i+1]->ID){
        temp = empSortedID[i]->ID;
        empSortedID[i]->ID = empSortedID[i+1]->ID;
        empSortedID[i+1]->ID = temp;
        z = 1;
      }
    }
  } while(z == 1);


  empDB.empSSN = empSortedSSN;
  empDB.empID = empSortedID;

  return empDB;
}

Employee * findEmpBySSN(int SSN, empDatabase data){
  if(data.empSSN == NULL)
    return NULL;

  Employee** emp = data.empSSN;
  int first = 0;
  int last = data.size;
  int mid = (first+last)/2;
  if(SSN > emp[mid]->SSN){
    data.empSSN = &emp[mid+1];
    data.size = data.size - mid + 1;
    return findEmpBySSN(SSN, data);

  }
  else if(SSN < emp[mid]->SSN){
    data.empSSN = &emp[mid-1];
    data.size = mid-1;
    return findEmpBySSN(SSN, data);
  }
  else{
      return emp[mid];
  }
  return NULL;
}

Employee * findEmpByID(int ID, empDatabase data){
  if(data.empID == NULL)
    return NULL;

  Employee** emp = data.empID;
  int first = 0;
  int last = data.size;
  int mid = (first+last)/2;
  if(ID > emp[mid]->ID){
    data.empID = &emp[mid+1];
    data.size = data.size - mid + 1;
    return findEmpByID(ID, data);
  }
  else if(ID < emp[mid]->ID){
    data.empID = &emp[mid-1];
    data.size = mid-1;
    return findEmpByID(ID, data);
  }
  else{
      return emp[mid];
  }
  return NULL;
}

void freeEmpDatabase(empDatabase data){
  if(data.empSSN == NULL && data.empID == NULL)
    return;

  Employee** tmpFreeSSN = data.empSSN;
  Employee** tmpFreeID = data.empID;
  for(int i=0; i<data.size; i++){
    free(tmpFreeSSN[i]);
    free(tmpFreeID[i]);
  }
  free(tmpFreeSSN);
  free(tmpFreeID);
  tmpFreeSSN = NULL;
  tmpFreeID = NULL;
}

void printDatabase(empDatabase data){
  if(data.empSSN == NULL && data.empID)
    return;
  Employee** printEmpSSN = data.empSSN;
  Employee** printEmpID = data.empID;
  printf("In Ascending Order by SSN:\n");
  for(int i=0; i<data.size; i++){
    printf("Employee %d:\nSSN: %d\nID: %d\n\n", i, printEmpSSN[i]->SSN, printEmpSSN[i]->ID);
  }
  puts("");
  printf("In Ascending Order by ID:\n");
  for(int i=0; i<data.size; i++){
    printf("Employee %d:\nSSN: %d\nID: %d\n\n", i, printEmpID[i]->SSN, printEmpID[i]->ID);
  }
}
