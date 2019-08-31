/* Call-by-value vs. call-by-reference 

	swaping values

*/

#include <stdio.h>
 
void swapInts(int*, int*); // declare

int main () {

   /* local variable definition */
   int a = 100;
   int b = 200;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
 
   /* calling a function to swap the values */
   swapInts(&a,&b);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
 
   return 0;
}

void swapInts(int* input1, int* input2){
	int temp;
	temp = *input1;
	*input1 = *input2;
	*input2 = temp;
}
