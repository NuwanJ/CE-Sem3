#include <stdio.h>

int main(){
	int x = 10, y = 20;
	int *p = &x;
	p++;	// pointer arithmetic, works based on the type of the pointer
	printf("%d\n", *p);
	return 0;
}

