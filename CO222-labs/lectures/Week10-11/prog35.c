/* static keyword - local variables

	roshanr@pdn.ac.lk

*/

#include <stdio.h>
#define SIZE 5

int* readInt();

int main(){
	int *input, count;
	
	input = readInt();
	for(count = 0; count < SIZE; count++){
		printf("input[%d] = %d\n", count, input[count]);
	}
	return 0;
}

int* readInt(){
	int input[SIZE], count;
	for(count = 0; count < SIZE; count++){
		printf("Enter an integer: ");
		scanf("%d", &input[count]);
	}
	return input;
}
