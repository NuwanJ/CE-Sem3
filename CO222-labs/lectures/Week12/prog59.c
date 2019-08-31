/* Programmer Defined Data Types
	enum
	struct
	union
*/

#include <stdio.h>

typedef union _ {
	char c;
	int x;
	float y;
}newtype;

int main(){
	newtype var1;

	newtype vars[10];

	vars[0].x = 12;
	vars[1].y = 45.67;
	vars[2].c = 'A';

	var1.x = 12345677;
	
	printf("x = %d\n", var1.x);

	var1.y = 123.456;

	printf("x = %d\n", var1.x);
	printf("y = %f\n", var1.y);
	return 0;
}
