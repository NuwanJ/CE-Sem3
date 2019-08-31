/* user defined data types

	enum */

#include <stdio.h>

typedef enum bool_ {FALSE, TRUE} bool;

/* Line 7 is equivalent to :
	enum bool_ {FALSE, TRUE};
	typedef enum bool_ bool;
*/

int main(){
	int x, y;
	bool result;

	printf("enter x and y:");
	scanf("%d %d", &x, &y);

	result = x == y;

	if (result == TRUE){
		puts("they are equal");
	}else{
		puts("they are not equal");
	}
	return 0;
}
