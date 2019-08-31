// Week10_GCD.c
// Compute the greatest common divisor (GCD) of two
// non-negative integers, not both zero.

#include <stdio.h>

int gcd(int, int);

int main(void) {
	int num1, num2;

	printf("Enter two integers: ");
	scanf("%d %d", &num1, &num2);

	printf("gcd(%d, %d) = %d\n", num1, num2, gcd(num1, num2));
	return 0;
}

int gcd(int a, int b) {
	
	// a should greater than b

	if(b>a){
		int temp = a;
		a = b;
		b = temp;	
	}
	
	if(b==0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

