// Arrays

#include <stdio.h>

int main(){

	int array[10], *x, count;
	
	printf("%p\n", array);

	x = array + 1; 	// address/pointer arithmetic
 
	printf("%p\n", x); 

//	array[0]  ==> content of (array + 0)
//	array[2]  ==> content of (array + 2)

	for(count=0; count < 10; count++){
		x = array + count;
		printf("%p ------- ", x);
		printf("%p\n", &array[count]); 
	}
	

	return 0;	
}
