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

int detectColor(char* str);

int main(int argc, char **argv){
    
    if (argc != 4){
      printf("Not enough arguments\n");
      return -1;
    }  
    
    int bgColor = detectColor(argv[2]);
    int fgColor = detectColor(argv[3]);
    
    if(strcmp(argv[1], "checker") == 0){
        // checker
    }else if (strcmp(argv[1], "donut") == 0 ){
        // donut 
    }else{
        printf("Requested figure is not available\n");
        return -1;
    }
    
    if (bgColor==-1){
        printf("Background color is not available\n");
        return -1;
        
    } else if (fgColor==-1){
        printf("Foreground color is not available\n");
        return -1;
    } 
    
    if(strcmp(argv[1], "checker")==0){
        drawChecker(fgColor, bgColor, 8);
        
    }else if (strcmp(argv[1], "donut")==0){
        int s = 0;
        scanf("%d", &s);
        drawDonut(fgColor, bgColor, (s/2));    
        
    }else{
        // TODO: Remove this 
        printf("%s\n", argv[1]);
        //drawDonut(fgColor, bgColor, 10);    
    }
    
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
                textcolor(BRIGHT, bgColor, fgColor);	
                printf(" ");    
                
            }else{
                // BG
                textcolor(BRIGHT, fgColor, bgColor);	
                printf(" ");
            }
        }
        textcolor(RESET, WHITE, BLACK);
        printf("\n");
    }
    
}



void drawChecker(int fgColor, int bgColor, int s){
    
    int i, j, k=0;  
    int grid = 8;
	
    for(i=0;i<(s*grid);i++){
        
        if((i%8)==0){
              k = 1-k;
        }
        
        for(j=0;j<(s*grid);j++){
            
            if((j%8)==0){
              k = 1-k;
            }
        
            if(k==1){
                textcolor(BRIGHT, fgColor, bgColor);	
                printf(" ");
            }else{
                textcolor(BRIGHT, bgColor, fgColor);	
                printf(" ");
            }    
        }
        
		    textcolor(RESET, fgColor, bgColor);
        printf("\n");

    }

	textcolor(RESET, WHITE, BLACK);	
    
}


int detectColor(char* str){
    
    if(strcmp(str, "black")==0){
        return BLACK;
    }else if(strcmp(str, "red")==0){
        return RED;
    }else if(strcmp(str, "green")==0){
        return GREEN;
    }else if(strcmp(str, "yellow")==0){
        return YELLOW;
    }else if(strcmp(str, "blue")==0){
        return BLUE;
    }else if(strcmp(str, "magenta")==0){
        return MAGENTA;
    }else if(strcmp(str, "cyan")==0){
        return CYAN;
    }else if(strcmp(str, "white")==0){
        return WHITE;
    }else{
        return -1;
    }
}

void textcolor(int attr, int fg, int bg)
{	
  char command[13];

	/* Command is the control command to the terminal */
	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in black in white background */

	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}