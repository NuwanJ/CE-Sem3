// This is a single line comment

/*
	This is my first programme in C

	This program prints Hello CO222

	As many lines as you want.....

	C-Prog --Pre-processing-->  Pre-processed C-Prog --Compling--> Assembly-Prog 

		--Assembling--> Object-Code --Linking (static/dynamic)--> Linked-Prog 

	gcc -o prog01 prog01.c

	gcc -E prog01.c  -- output to the screen
	gcc -S prog01.c  -- output a file with the same filename and .s extension
	gcc -c prog01.c  -- output a file with the same file name and .o extension

*/

#include <stdio.h>  // include standard input/output (header file contains signatures)


int main(){	// function block
		// return value of a function - int here stands for integer (type)

	printf("Hello CO222\n");

	return 0;
}


