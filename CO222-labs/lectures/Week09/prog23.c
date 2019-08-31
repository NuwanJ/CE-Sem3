/* functions
	call-by-value
	call-by-reference (address)
*/

#include <stdio.h>

int func(int);	// function signature

int main(){
	int x = 10, z;

	printf("before the function call x = %d\n", x);
	z = func(x);	
	printf("after the function call x = %d\n", z);

	return 0;
}

int func(int y){
	y++;
	return y;
}	
