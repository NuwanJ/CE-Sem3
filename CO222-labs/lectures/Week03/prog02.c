/* input, output

*/

#include <stdio.h>

int main(){
	
	int val, returnVal1, returnVal2;

	// man 3 scanf - return value
	returnVal1 = scanf("%d", &val);

	// man 3 printf - return value
	returnVal2 = printf("val = %d\n", val);

	// print the returned values
	printf("return value1 = %d, return value2 = %d\n", returnVal1, returnVal2);

	return 0;
}
