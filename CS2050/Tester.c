#include<stdio.h>
#include<stdlib.h>

typedef struct{
 float salary;
} Employee;

int main(void){
/*  Employee * empArray[100];
  for(int i=0;i<100; i++){
    empArray[i] = malloc(sizeof(Employee));
  }
  for(int j=0; j<100; j++){
    empArray[j]->salary=0.0;
    printf("Employee %d = %.2f\n", j, empArray[j]->salary);
  }
  empArray[98]->salary = 100.00;
  printf("\n\nEmployee 98 = %f\n", empArray[98]->salary);

  Employee *l = malloc(1000*sizeof(Employee));
  l[10].salary = 100.50;
  printf("\n\nEmployee 10 = %.2f\n", l[10].salary);
  int i;
  char p = 'C';
  i = p;
  printf("%d\n", p);

  int array[100][20];
  int m, n;
  for(m=0; m<20; m++){
    for(n=0; n<100; n++){
      array[m][n]=1;
      //printf("array[%d][%d] = %d\n", m, n, array[m][n]);
    }
  }*/

  int *p = NULL, n=5;
  p = &n;
  n = 200;
  printf("%d\n", *p);

//  for(q = list->next; q->key<p->key; q= q->next) //To set a pointer at a specific point in a linked list with Dummy Node..
}
