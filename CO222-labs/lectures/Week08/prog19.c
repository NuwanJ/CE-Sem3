// Arrays

#include <stdio.h>

#define SIZE 5

int main(){

	int array[SIZE], count;
	
	for(count=0; count < SIZE; count++){
		scanf("%d", array+count);
	}
	
	for(count=0; count < SIZE+100; count++){
		printf("%d\n", array[count]);
	}

	return 0;	
}
