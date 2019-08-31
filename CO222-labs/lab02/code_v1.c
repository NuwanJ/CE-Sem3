/*****************************************

CO222: Lab2
Author		: Jaliyagoda A.J.N.M
Last update : 2018/02/14

*****************************************/

#include <stdio.h>

int playerValue(char p);

int main(){

	char p1 = 'W';
	char p2 = 'W';
	char res = 'D';

	int p1Val = 0, p2Val=0;

	char val[] = {'R','P','C','S','L'};

	int read = scanf("%c %c", &p1, &p2);
	int diff = 0;


	if (read == 2){				// Valid scanf

		// Updating player 1's value
		p1Val = playerValue(p1);
		p2Val = playerValue(p2);

		diff = p1Val - p2Val;

		if(diff<0){ 			// minus differance range

			diff = diff * -1;

			if (diff==1 || diff==3){
				printf("Player 2 wins\n");
			}else{
				printf("Player 1 wins\n");
			}

		}else if(diff>0){		// positive range

			if (diff==1 || diff==3){
				printf("Player 1 wins\n");
			}else{
				printf("Player 2 wins\n");
			}

		}else{
			printf("Tie\n");
		}
	}else{
		printf("Wrong input\n");
	}
	return 0;
}

int playerVal(char p){
	char val[] = {'R','P','C','S','L'};

	for (int i=0; i<6;i++){
			if(i==5){
					return -1;

			}else if(p==val[i]){
					return i;
					break;
			}
	}
}
