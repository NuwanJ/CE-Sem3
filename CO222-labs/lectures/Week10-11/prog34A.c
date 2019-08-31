/* static keyword - functions 

	https://www.geeksforgeeks.org/what-are-static-functions-in-c/

	roshanr@pdn.ac.lk

*/

/* Part A */

#include <stdio.h>

int inc(int);
static int dec(int);

int main(){
	printf("%d\n", inc(10));
	printf("%d\n", dec(10));
	return 0;
}

int inc(int x){
	return ++x;
}
