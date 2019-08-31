/* static keyword - global variables

	static var_type var_name;

	roshanr@pdn.ac.lk

*/


/* Part A */

#include <stdio.h>

void magic();
static int count; // hiding a global variable from other files 

int main(){
	
	count = 1;
	printf("count = %d \n", count); // 1

	magic();

	printf("count = %d \n", count); // 3
	return 0;
}
