// pre-processor directive - typedef
// typedef is used to give another name to existing types

// having our own?? - user defined types? 

#include <stdio.h>

typedef int number;

int main(){
	// types - pre-defined / inbuilt
		// char, int, short, long....
		// float, double
	int var1 = 12;
	number var2 = 123;

	printf("var2 = %d\n", var2);

	return 0;
}
