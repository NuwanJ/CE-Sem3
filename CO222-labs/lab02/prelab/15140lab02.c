

// Lab2
// Jaliyagoda A.J.N.M
// Last update : 2018/02/14

#include <stdio.h>


int main(){

	char p1 = 'W';
	char p2 = 'W';
	char res = 'D';

	int p1Val = 0, p2Val=0;

	char val[] = {'R','P','C','S','L'};
	
	int read = scanf("%c %c", &p1, &p2);
	int diff = 0;


	if (read ==2){
		// Valid input

		// Updating player 1's value		
		for (int i=0; i<6;i++){
			if(i==5){
					//Wrong input
					printf("Wrong input\n");
					return 0;

			}else if(p1==val[i]){
					// Player1's value find. Next player 2
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

		
		diff = p1Val - p2Val;

		if(diff<0){
			// - range	
			
			diff = diff * -1;
			
			if (diff==1 || diff==3){
				printf("Player 2 wins\n");
			}else{
				printf("Player 1 wins\n");
			}

		}else if(diff>0){
			// positive range

		
			if (diff==1 || diff==3){
				printf("Player 1 wins\n");
			}else{
				printf("Player 2 wins\n");
			}
			
		}else{
			// Tie
			printf("Tie\n");
		}

		
		//printf("Player1: %c Player2: %c \n", p1, p2);
		//printf("Player1: %d Player2: %d \n", p1Val, p2Val);

	}else{
		// Invalid input
		printf("Wrong input\n");

	}


	return 0;
}