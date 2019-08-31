/*	Break & C - C
	
	Calculate  the sum and average of 10 numbers (integers). 
	Skip the negative numbers from the calculations.

	roshanr@pdn.ac.lk
*/

#include <stdio.h>

#define MAX 10

int main(){
	int count, real_count = 0, input, sum = 0;

	for(count = 1; count <= MAX; count++){
		scanf("%d", &input);
		if (input < 0){
			continue;
		}else{	
			sum += input;
			real_count++;
		}
	}

	printf("sum = %d, avg = %.2lf\n", sum, sum/(double)real_count);
	return 0;
}
