//Greg Ryterski
//gjr7dz, 18186949
//Lab, Group E
#include<stdio.h>
#include<stdlib.h>

//Prototypes
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs);

int main(void){
  int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,
  66,69,63,93,77,98,99,40,88,49};

  int NoOfAs=0;
  int NoOfBs=0;
  int NoOfCs=0;
  int size = sizeof(array)/ sizeof(array[0]); //Finds the size of the array, 30 in this case
  int BBoundary = 80, CBoundary = 60; //Gives the boundarys for grading

  countGrades(array, size, BBoundary, CBoundary, &NoOfAs, &NoOfBs, &NoOfCs);  //Sends the function the variables to count the grades of students

  printf("%d students got A, %d students got B, and %d students got C.\n", NoOfAs, NoOfBs, NoOfCs); //Prints out how many students got each grade from the array
}

//Function is created to count the number of students that fall into the grading of A, B, or C
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs){
  int i;
  for(i=0; i<size; i++){
    if(arr[i]<CBoundary){   //Checks to see if the students grade is below 60 and gives them a Grade C
      (*NoOfCs)++;
    }

    if(arr[i]>=CBoundary){  //Gives a B grade to a student if their grade is above or equal to 60
      (*NoOfBs)++;
    }

    if(arr[i]>=BBoundary){ //Gives a A grade to students above or equal to 80
      (*NoOfAs)++;
      (*NoOfBs)--;  //Removes the B grade to give the student only one grade instead of two
    }
  }
}
