
#include <stdio.h>

typedef struct _ {
	int x;	// 4 bytes
	float y;
	double z;
} newtype;

/* 
	compile and then object dump (objdump -s binaryfile)
	and look at the .DATA segmment

double y = 1.2345;
int x = 0x12345678;
int x1 = 0x88888888;
int x2 = 0x99999999;
char c = 'A';
*/

int main(){
	newtype var2;	// debugger - gdb


	printf("%lu\n", sizeof(var2));


	return 0;
}
