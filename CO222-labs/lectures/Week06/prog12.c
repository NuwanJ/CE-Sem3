/* LOOPS

	while
	for

	print a constant number of stars 
*/

#define COUNT 10

#include <stdio.h>

int main(){

	int counterW = 0, counterF;

	while(counterW < COUNT){
		putchar('*'); // puts("*"); //printf("*");
		counterW++;
	}

	// syntatic sugar
	for(counterF = 0; counterF < COUNT; counterF++){
		putchar('*'); // puts("*"); //printf("*");
	}

	return 0;
}
