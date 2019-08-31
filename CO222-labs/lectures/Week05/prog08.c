/* chars - represented using numbers 

	takes a char and say whether it is CAPITAL or simple

*/

#include <stdio.h>
#include <ctype.h>	// int isupper(char), int islower(char), isalpha, isnum

int main(){
	
	char input;	

	//scanf("%c", &input);
	//input = getchar(); // gets a char from the standard input
	input = getc(stdin); // streams

	if(isupper(input)){   // (input >= 'A') && (input <=  'Z')){
		//printf("It is CAPITAL\n");
		puts("It is CAPITAL");
	}else if ((input >= 'a') && (input <=  'z')){
		printf("It is simple\n");
	}else{
		printf("Not an alphabet\n");
	}
	
	// toupper / tolower functions, how they work??

	return 0;
}
