// variables, refereces, and dereferences

#include <stdio.h>

int main(){

	int number;
	int *nptr;
	
	printf("The address of number: %p\n", &number); 
	printf("The address of nptr: %p\n", &nptr);
	printf("nptr: %p\n", nptr);  

	number = 10*15;
	printf("The address of number: %p\n", &number);  
   
	nptr= &number;
	printf("The address in nptr: %p\n", nptr);  
	printf("The value of number: %d\n", *nptr);  // value of nptr
	return 0;
}   
