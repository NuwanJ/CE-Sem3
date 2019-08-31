// User defined types: (1) enumatared datatype - enum & typedef


#include<stdio.h>

// An enum is only guaranteed to be large enough to hold int values. 
// The compiler is free to  choose the actual type used based on the
// enumeration constants  defined so it can choose a smaller type if
// it can represent the values you define.

typedef enum _ {	JAN = 1, 
					FEB,
					MAR,
					APR,
					MAY,
					JUN,
					JUL,
					AUG,
					SEP,
					NOV,
					DEC} 
	month_t;


	
int main(){
	month_t myMonth;
	myMonth= MAR;
	printf("My month number is %d\n", myMonth);
	return 0;
}