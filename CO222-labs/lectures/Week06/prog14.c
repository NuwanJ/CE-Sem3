/*
	find sum & average of a max COUNT number of positive numbers that the user enters
	stop the program when the user enters a negative number

*/

#include <stdio.h>

#define COUNT 10

int main(){

	int input, counter = 0, sum = 0;

	while(counter < COUNT){
		scanf("%d", &input);
		if (input >= 0){
			sum += input; // sum = sum + input;
			counter++;
		}else{
			break;
		}
	
	}
	
	printf("The sum is %d and the average is %f\n", sum, sum/(float)counter);
	
	return 0;
}
