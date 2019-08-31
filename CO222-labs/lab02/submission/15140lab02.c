/*****************************************

CO222: Lab2 
Author		: Jaliyagoda A.J.N.M (E/15/140)
Last update : 2018/02/15

Notes		: Code implemented without using functions

*****************************************/

#include <stdio.h>

int main(){

	char p1 = 'W',p2 = 'W';
	int p1Val = 0, p2Val = 0;

	char val[] = {'R','P','C','S','L'};
	
	int read = scanf("%c %c", &p1, &p2);
	int diff = 0;

	if (read == 2){				
		// Valid scanf

		// Updating player 1's value		
		for (int i=0; i<6;i++){
			if(i==5){
					//Wrong input
					printf("Wrong input\n");
					return 0;

			}else if(p1==val[i]){
					// Player1's value found
					p1Val = i;	
					break;		
			}
		}	

		// Updating player 2's value
		for(int j=0;j<6;j++){
			if(j==5){
					//Wrong input for player2
					printf("Wrong input\n");
					return 0;

			}else if(p2==val[j]){
					p2Val = j;
					break;		
			}
		}

		// Calculate the player 2's position value relative to player 1's
		diff = p1Val - p2Val;

		if(diff==0){
			// Both entered same value - Tie
			printf("Tie\n");
	
		}else{
		
			// Format minus relative to positive and shift by one to minimize the code
			if(diff<0) {
				diff= diff*-1 + 1;
			}

			// If the relative position in an odd number, player 1 is won
			if (diff%2==1){		
				printf("Player 1 wins\n");
			}else{
				printf("Player 2 wins\n");
			}			
		}

	}else{
		// Invalid scanf reading
		printf("Wrong input\n");
	}

	return 0;
}
