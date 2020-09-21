//Greg Ryterski
//18186929, gjr7dz
//Group E, Lab 1

#include <stdlib.h>
#include <stdio.h>

int addition(int arr[], int size); //function prototype

int main(void) {
	
		int size = 5;
		int sum = 0;
		int arr[5] = {5,10,8,2,13};
		
		printf("Array is:");
		for(int i=0; i<size; i++) {
			printf("%d", arr[i]); //prints the values in the array
			if(i!=4)
				printf(",");
		}
		printf("\n");
		
		sum = addition(arr, size);	//calls the function addition to add values in the array
		
		printf("Sum is:%d\n", sum);
}

int addition(int arr[], int size) {

	int sum = 0;
	
	for(int i=0; i<size; i++) {
	sum += arr[i];	//adds the values to the variable "sum"
	}
	
	return sum;
}