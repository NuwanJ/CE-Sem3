/* Pointers and references */

#include <stdio.h>

int main(){

	int x;
	int *p;

	p = &x;

	x = 200;
	
	printf("%p has %d\n", p, *p);

	return 0;

}
