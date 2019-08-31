/* constants
	(1) use variables with the keyword const
	(2) pre-processor gcc -E
*/

#include <stdio.h>  // include is called a pre-processor derective
#define CLASS_SIZE 60

int main(){

	const int CONST_VAR = 12; // constVar; // renaming variable
//	const int CLASS_SIZE = 60;

	int Total = 1000;


	printf("Class average is %f\n", Total/(float)CLASS_SIZE);
									// casting
	// CLASS_SIZE = 59; //-- this will produce an error 

	return 0;
}
