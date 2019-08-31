/* prog25.c

	Functions - call by value vs. call by reference

	roshanr@pdn.ac.lk
*/

#include<stdio.h>

int incVal(int);   // call by value
int incRef(int*);  // call by reference / pointer / address

int main(){
	int val = 10;
	// check the values before and after calling the functions

	// call by value
	printf("%d\n", incVal(val));
	printf("%d\n", val);

	// call by reference
	printf("%d\n", incRef(&val));
	printf("%d\n", val);

	return 0;
}

int incVal(int p){
	return ++p;
}

int incRef(int* ptr){
	return ++(*ptr);
}
