/* functions
	call-by-value
	call-by-reference (address)
*/

#include <stdio.h>

void func(int*);	// function signature

int main(){
	int x = 10;

	printf("%p\n", &x);

	printf("before the function call x = %d\n", x);
	func(&x);	
	printf("after the function call x = %d\n", x);

	return 0;
}

void func(int* y){
	printf("%p\n", y);
	(*y)++;
	return;
}	
