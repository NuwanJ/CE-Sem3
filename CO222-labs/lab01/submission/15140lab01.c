/*
	Lab 01: Electricity Bill Calculator
	Author: Jaliyagoda A.J.N.M. (E/15/140)
	Last Update: 25/01/2018
*/

#include <stdio.h>

int main(){

	int n = 0;							// Number of units
	double usageCharges = 0.0;			// Charges for units
	double fixedCharges = 0.0;			// Fixed Charges

	scanf("%d", &n);					// Input the number of units

	if(n<=0){
		// Giving error result if input isn't a valid integer
		printf("-1\n");

	}else{
		if(n <=30){
			// 0-30
			fixedCharges = 30.00;
			usageCharges = (n*2.50);

		}else if (n<=60){
			// 31-60
			fixedCharges = 60.00;
			usageCharges = (30*2.50) + (n-30)*4.85;

		}else if (n<=90){
			// 61-90
			fixedCharges = 90.00;
			usageCharges = 7.85*60 + (n-60)*10.00;

		}else if (n<=120){
			// 91-120
			fixedCharges = 480.00;
			usageCharges = 7.85*60 + 30*10.00 + (n-90)*27.75;

		}else if (n<=180){
			// 121-180
			fixedCharges = 480.00;
			usageCharges = 7.85*60 + 30*10.00 + 30*27.75 + (n-120)*32.00;

		}else{
			// >180
			fixedCharges = 540.00;
			usageCharges = 7.85*60 + 30*10.00 + 30*27.75 + 60*32.00 + (n-180)*45.00;
		}

		//For debugging purpose
		//printf("Usage: %d units\n", n);
		//printf("Bill: For Usage: Rs.%.2f | Fixed Charges: Rs.%.2f\n", usageCharges, fixedCharges);
		//printf("Total: Rs.%.2f\n", usageCharges+fixedCharges);

		printf("%.2f\n", usageCharges + fixedCharges);

	}
	return 0;
}
