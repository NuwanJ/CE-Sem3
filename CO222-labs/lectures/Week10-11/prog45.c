#include<stdio.h>

int main(){
	int count, count1;
	int array1[5] = {0,1,2,3,4};
	int array2[5] = {4,3,2,1,0};
	int *array3;
	
	for (count = 0; count < 5; count++)
		printf("array1[%d] = %d \t", count, array1[count]);
	
	printf("\n");
	
	for (count1 = 0; count1 < 5; count1++)
		printf("array2[%d] = %d \t", count1, array2[count1]);

	printf("\n");
			
	array1[0] = array2[0];
	
	for (count = 0; count < 5; count++)
		printf("array1[%d] = %d \t", count, array1[count]);
	
	printf("\n");
			
	array3 = array1;
//	array2 = array1;	 // IS THIS POSSIBLE?
	
	for (count = 0; count < 5; count++)
		printf("array3[%d] = %d \t", count, array3[count]);

	printf("\n");
	
	array3++;
	printf("array3[0] = %d \n", array3[0]);
	
	
	printf("data in (array1 + 1) = %d \n", *(array1 + 1));
	
	
	return 0;
}
