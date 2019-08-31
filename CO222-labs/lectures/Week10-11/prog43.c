#include <stdio.h>

#define SIZE 10

int print_int_array(int* y, int size){
	int count;
	for (count = 0; count < size; count++)
		printf("y[%d] = %d\n", count, y[count]);	

	return 0;
}

int main(){
	int x[10] = {0,1,2,3,4,5,6,7,8,9};
	
	// if we are to pass an array and need to find the size 
	// in the callee, it is not possible. therefore we need
	// to pass the size of the array as well.

	// char array is an exception as we use '\0' to indicate
	// the end of the array. eg: strlen(char *);
	print_int_array(x, 10);
	
	return 0;
}
