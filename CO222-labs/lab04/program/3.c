#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void drawChecker(int fgColor, int bgColor, int r);
void drawDonut(int fgColor, int  bgColor, int r);

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

    int bgColor,fgColor ;
    
    int s = 20;

    
    bgColor = RED;
    fgColor = GREEN;
    
    //drawChecker(fgColor, bgColor, s);
    drawDonut(fgColor, bgColor, s);
    
    return 0;
}


void drawDonut(int fgColor, int  bgColor, int r){
    int  i=0, j=0;
    int g[100][100] = {};
    
    // Great circle
    for(i=0;i<r+1;i++){
        
        int l = sqrt((r*r)-(i*i));
        
        for(j=0;j<l;j++){
            
            g[r+i][r+j] = 1;
            g[r-i][r-j] = 1;
            
            g[r+i][r-j] = 1;
            g[r-i][r+j] = 1;
        
        }
    }
    
    // Small circle
    for(i=0;i<(r/2);i++){
        
        int l = sqrt((r*r*0.4)-(i*i));
        
        for(j=0;j<l;j++){
            
            g[r+i][r+j] = 0;
            g[r-i][r-j] = 0;
            
            g[r+i][r-j] = 0;
            g[r-i][r+j] = 0;
        
        }
    }
    for(i=1;i<(2*r);i++){
        for(j=1;j<(2*r);j++){
            
            int b = g[i][j];
            
            if(b==1){
                textcolor(BRIGHT, fgColor, bgColor);	
                printf("   ");    
                
            }else{
                // BG
                textcolor(BRIGHT, bgColor, fgColor);	
                printf("   ");
            }
        }
        textcolor(RESET, WHITE, BLACK);
        printf("\n");
    }
    
    
    
    
    /*int i, j;
    int bg1, bg2;    
    int d = 0, l=0;
    
    for(i=0;i<r;i++){
        
        d = (i>= (r/2))? i : (r-i);
        l = sqrt((r*r)-(d*d));
        
        // until radius
        for (j=0;j<(r-l);j++){
            textcolor(RESET, WHITE, BLACK);	
            printf(" ");
        }
        
        // Until diameter
        for (j=(r-l);j<r;j++){
            textcolor(BRIGHT, fgColor, bgColor);
            printf(" ");
        }s
        
        for(j=0;j<l;j++){
            
            textcolor(BRIGHT, fgColor, bgColor);	
            printf(" ");
            
        }
        
		textcolor(RESET, WHITE, BLACK);
        printf("\n");
    }

	textcolor(RESET, WHITE, BLACK);	*/
}




void drawChecker(int fgColor, int bgColor, int s){
    
    int i, j, jj;
    int bg1, bg2;    
    
    for(i=0;i<s;i++){
        
        bg1 = (i%2==1)?1:0;
        
    	for (jj=0;jj<8;jj++){
            
            for(j=0;j<s;j++){
                
                bg2 = (j%2==1)?1:0;
            
                if((bg1+bg2)%2==1){
                    textcolor(BRIGHT, fgColor, bgColor);	
                    printf("   +    ");
                }else{
                    textcolor(BRIGHT, bgColor, fgColor);	
                    printf("   0    ");
                }    
            }
            
    		    textcolor(RESET, WHITE, BLACK);
            printf("\n");
    	    }
      }

	textcolor(RESET, WHITE, BLACK);	
    
    
    
    
    
}
