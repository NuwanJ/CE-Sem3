/* user defined data types

	enum */

#include <stdio.h>

enum bool {FALSE, TRUE};

int main(){
	int x, y;
	enum bool result;

	printf("enter x and y:");
	scanf("%d %d", &x, &y);

	result = x == y;

	if (result == TRUE){
		puts("they are equal");
	}else{
		puts("they are not equal");
	}


	return 0;
}
