/*
	use of return value of a scanf in returning an error code to 
	the caller of this program (via main function's return value).	

	in the shell try,
		$echo $?  - $? is the system variable where the return value is kept


*/

#include <stdio.h>


int main(){

	int var1, var2, sum, return_value;

	return_value = scanf("%d %d", &var1, &var2);
	
	if (return_value == 2){
		sum = var1 + var2;
		printf("the sum of %d and %d is %d\n", var1, var2, sum);
	}else{
		printf("you should enter two numbers\n");
		return 1;
	}

	return 0;
}
