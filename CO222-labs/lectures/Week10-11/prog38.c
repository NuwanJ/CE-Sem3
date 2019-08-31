/* Pointers and references */

#include <stdio.h>
#include <stdlib.h>

int main(){

	int *p;

	// method 1:  static
	int space;
	p = &space;
	*p = 200;
	printf("%p has %d\n", p, *p);

	// method 2: dynamic
	p = (int*) malloc(sizeof(int));
	*p = 500;
	printf("%p has %d\n", p, *p);
	free(p);

	return 0;

}
