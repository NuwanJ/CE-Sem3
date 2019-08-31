/*
	find sum & average COUNT number of positive numbers that the user enters (user might enter negative numbers as well)

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
		}
	}
	
	printf("The sum is %d and the average is %f\n", sum, sum/(float)COUNT);
	
	return 0;
}
