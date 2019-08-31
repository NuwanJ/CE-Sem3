/*
	Lab3-Exercise 01
	E15140
*/


#include <stdio.h>

int main(){

	int n=0, i=0, j=0;
	int reading = scanf("%d", &n);

	if(reading == 1 && n>0) {
		// Valid input

		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				(i==0 || i==n-1 || j==0 || j==n-1) ? printf("*") : printf(" ");
			}
			printf("\n");
		}

	}else{ 
		//Invalid input

		printf("Invalid input");
	}
	return 0;
}


