#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in black in white background */

	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}


int main(int argc, char **argv){

    //printf("%s\n", argv[0]);
	//rintf("%s\n", argv[1]);


    int s = 8;
    int i = 0, j = 0;
    int bg1, bg2;    

    
    for(i=0;i<s;i++){
        
        bg1 = (i%2==1)?1:0;
        
        
        for(j=0;j<s;j++){
            
            bg2 = (j%2==1)?1:0;
        
            if((bg1+bg2)%2==1){
                textcolor(RESET, BLACK, WHITE);	
                printf("  ");
            }else{
                textcolor(RESET, WHITE, BLACK);	
                printf("  ");
            }    
        }
		  textcolor(RESET, WHITE, BLACK);	   
        printf("\n");
    }



	textcolor(RESET, WHITE, BLACK);	
	return 0;
	
	
}
