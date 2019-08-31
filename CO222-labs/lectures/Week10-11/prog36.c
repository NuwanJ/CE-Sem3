/* returning local variables 

   roshanr@pdn.ac.lk
*/

#include<stdio.h>

char* returnStr1();
char* returnStr2();

int main(){
	char* one = returnStr1();
	char* two = returnStr2();
	
	printf("[%s]\n", one);
	printf("[%s]\n", two);
	
	return 0;
}

char* returnStr1(){
    static char p[] = "CO222";  // ??
    return p;
}

char* returnStr2(){
    static char p[] = "Programming Methodology"; 		// ??
    return p;
}


