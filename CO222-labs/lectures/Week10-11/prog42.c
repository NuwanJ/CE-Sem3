/* prog46.c

*/

#include <stdio.h>

#define SIZE 10


int main(){

	int arr[SIZE];
	int *arrp;
	
	arrp = arr; // this is correct and not arr = arrp; (you cannot change an array name)
	

	printf("size of arr is %lu\n", sizeof(arr));
	printf("size of arrp is %lu\n", sizeof(arrp));

	return 0;
}




