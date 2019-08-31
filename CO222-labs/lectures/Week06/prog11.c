/* compound assignments */

#include <stdio.h>

int main(){

	int x = 10, y;

	x++;		// x = x + 1;
	++x;		// x = x + 1;

	y = ++x;	// x = x + 1; y = x;
	y = x++;	// y = x; x = x + 1;

	printf("%d", (x++));	// 

	//return x++;	// return 10
	//return ++x;	// return 11
	return 0;
}

