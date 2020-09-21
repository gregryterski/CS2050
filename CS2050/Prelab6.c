//Greg Ryterski
//gjr7dz, 18186949
//Prelab 6
#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int ID, jobType;
  float salary;
} Employee;

Employee * readEmployeeInfo(FILE *fp, int *numElems);
Employee * getEmployeeByID(Employee *emp, int numEmps, int ID);
void setID(Employee *p, int id);
int getID(Employee *p);
void setSalary(Employee *p, float salary);
void printEmployee(Employee *p, int numEmps);
void freeFiles(Employee *p);

int main(void){
  int numElems;
  FILE *fptr = fopen("Employee.txt", "r");
  if(fptr == NULL){
    printf("There is nothing in the file or it doesn't exist.\n");
    return 0;
  }
  Employee * files = readEmployeeInfo(fptr, &numElems);
  printEmployee(files, numElems);
  freeFiles(files);

  fclose(fptr);
}

Employee * readEmployeeInfo(FILE *fp, int *numElems){
  fscanf(fp, "%d\n", numElems);
  Employee * employees = malloc(sizeof(Employee) * (*numElems));
  if(((void*)employees) == NULL){
    printf("Malloc has failed to allocate memory.\n");
  }
  for(int i=0; i<(*numElems); i++)
    fscanf(fp, "%d %d %f\n", &employees[i].ID, &employees[i].jobType, &employees[i].salary);

  return employees;
}

Employee * getEmployeeByID(Employee *emp, int numEmps, int ID){
  Employee * empRecord = NULL;
  for(int i=0; i<numEmps; i++){
    if(ID == emp[i].ID){
      empRecord = &emp[i];
      break;
    }
  }
  if(empRecord == NULL)
    return NULL;

  return empRecord;
}

void setID(Employee *p, int id){
  p->ID = id;
}

int getID(Employee *p){
  return p->ID;
}

void setSalary(Employee *p, float salary){
  p->salary = salary;
}

void printEmployee(Employee *p, int numEmps){
  Employee * emp = getEmployeeByID(p, numEmps, 10000010);
  printf("Employee 10000010 before adjusting:\n");
  printf("ID: %d\nJobType: %d\nSalary: %.2f\n", emp->ID, emp->jobType, emp->salary);
  printf("\nAdjusting...\n\n");
  int randomID = rand() + 10000000;
  setID(emp, randomID);
  int newID = getID(emp);
  float newSalary = abs(rand() / 10000);
  setSalary(emp, newSalary);
  printf("Employee 10000010's new file:\n");
  printf("ID: %d\nJobType: %d\nSalary: %.2f\n", newID, emp->jobType, emp->salary);
}

void freeFiles(Employee *p){
  free(p);
}
