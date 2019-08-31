// User defined types: (1) enumatared datatype - enum 
//
// Why are they useful - example

#include<stdio.h>
#include<string.h>

// An enum is only guaranteed to be large enough to hold int values. 
// The compiler is free to  choose the actual type used based on the
// enumeration constants  defined so it can choose a smaller type if
// it can represent the values you define.

enum color_type {UNKNOWN, RED, YELLOW, BLUE};

int    			getColor1();
char*  			getColor2();
enum color_type getColor3();

int main(){	
	// three different ways of getting a color from the user and printing 
	// an appropriate message.

	// use getColor1()
	int color1 = getColor1();
	if (color1 == 0) // Red
		puts("The user entered red");
	else if (color1 == 1) // Yellow
		puts("The user entered yellow");
	else if (color1 == 2) // Blue
		puts("The user entered blue");
	else
		puts("The user didn't enter a right color");
	
	// use getColor2()
	char* color2 = getColor2();
	if (!strcmp(color2, "Red")) 
		puts("The user entered red");
	else if (!strcmp(color2, "Yellow")) 
		puts("The user entered yellow");
	else if (!strcmp(color2, "Blue")) 
		puts("The user entered blue");
	else
		puts("The user didn't enter a right color");

	// use getColor3()
	enum color_type color3 = getColor3();
	if (color3 == RED) 
		puts("The user entered red");
	else if (color3 == YELLOW) 
		puts("The user entered yellow");
	else if (color3 == BLUE) 
		puts("The user entered blue");
	else
		puts("The user didn't enter a right color");
	
	return 0;
}

int getColor1(){
	char c;
	printf("Choose a color (R - Red, Y - Yellow, B - Blue): ");
	scanf("%c",&c);	fflush(stdin);
	switch (c){
		case 'R': return 0; 
		case 'Y': return 1;
		case 'B': return 2;
		default : return -1; 
	}
}

char* getColor2(){
	char c;
	printf("Choose a color (R - Red, Y - Yellow, B - Blue): ");
	scanf("%c",&c); fflush(stdin);
	switch (c){
		case 'R': return "Red"; 
		case 'Y': return "Yellow";
		case 'B': return "Blue";
		default : return "Unknown"; 
	}
}

enum color_type getColor3(){
	char c;
	printf("Choose a color (R - Red, Y - Yellow, B - Blue): ");
	scanf("%c",&c);	fflush(stdin);
	switch (c){
		case 'R': return RED; 
		case 'Y': return YELLOW;
		case 'B': return BLUE;
		default : return UNKNOWN; 
	}
}
