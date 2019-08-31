#include <stdio.h>

#define SIZE 10

void printArray(int*, int);

int main(){
	int array[SIZE];
	int * arrayP;

	arrayP = array;

	//array = arrayP;  -- you can't update the variable array but
	//					 the content

	printf("the size of array is %lu bytes\n", sizeof(array));
	printf("the size of *arrayP is %lu bytes\n", sizeof(*arrayP));

	printArray(array, SIZE);

	return 0;
}

void printArray(int * a, int l){
	int count;
	for (count = 0; count < l; count++){
		printf("%d,\t", a[count]);
	}

}











