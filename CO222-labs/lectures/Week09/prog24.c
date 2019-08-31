/* functions
	call-by-value
	call-by-reference (address)
*/

#include <stdio.h>

char* return_hello();	// function signature

int main(){

	printf("%s", return_hello());

	return 0;
}

char* return_hello(){
	static char array[100] = "hello world!";
	return array;
}	
