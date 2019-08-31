/* Dangling Else

	You will get a warning from the compiler. Make sure you use
	the brakets (block brakets).

*/

#include <stdio.h>


int main(){
	int i = 0, j = 0; 

	if (!i)
		if (!j)
			puts("i and j are zero\n");
	else
		puts("i is not zero\n");
	
	return 0;
}
