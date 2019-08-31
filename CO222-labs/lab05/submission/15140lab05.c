
/******************************************************************************

	Author: Jaliyagoda A.J.N.M. (E/15/140)
	Last Update: 2018/04/26

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESET 0
#define BRIGHT 1

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define	WHITE 7


// Drawing Functions
void drawChecker(int fgColor, int bgColor, int r);
void drawDonut(int fgColor, int  bgColor, int r);
void drawDonut2(int fgColor, int  bgColor, int r);

//Color Functions
void textcolor(int attr, int fg, int bg);
int detectColor(char* str);


int main(int argc, char **argv){
    
    // Validate input arguments
    if (argc < 4){
      printf("Not enough arguments\n");
      return -1;
      
    }else if (argc>4){
      printf("Too many arguments\n");
      return -1;
	  }	
    
    // Validate figure
    if((strcmp(argv[1], "checker") != 0) && (strcmp(argv[1], "donut") != 0)){
        printf("Requested figure is not available\n");
        return -1;
    }
    
    // Validate input colors
    int bgColor = detectColor(argv[2]);
    int fgColor = detectColor(argv[3]);
    
    if (bgColor==-1){
        printf("Background color is not available\n");
        return -1;
        
    } else if (fgColor==-1){
        printf("Foreground color is not available\n");
        return -1;
    } 
    
    // Execute suitable function
    if(strcmp(argv[1], "checker")==0){
        drawChecker(fgColor, bgColor, 8);
        
    }else if (strcmp(argv[1], "donut")==0){
        int s = 0;
        int status = scanf("%d", &s);
        
        if(status==1){
            // Valid int input
            drawDonut2(fgColor, bgColor, s); 
        }
        
    }else{
        // Already rejected this option
    }
    
    return 0;
}

/*

void drawDonut(int fgColor, int  bgColor, int r){
    int i=0, j=0;
    int g[1000][1000] = {}; // This will support only circles below the radius of 500 points (Considered r > 500 as a rare situation)
    int l = 0;
	
    // Method one : Like Flood filling
    
    // Fill Big circle
    for(i=0;i<r;i++){
        l = sqrt((r*r)-(i*i));
        
        for(j=0;j<l;j++){
            
            g[r+i][r+j] = 1;
            g[r-i-1][r-j-1] = 1;
            
            g[r+i][r-j-1] = 1;
            g[r-i-1][r+j] = 1;
        
        }
    }
    
    // Unfill Small circle
    for(i=0;i<(r/2);i++){
        l = (sqrt((r*r/4)-(i*i)));
        
        for(j=0;j<l;j++){
            
            g[r+i][r+j] = 0;
            g[r-i-1][r-j-1] = 0;
            
            g[r+i][r-j-1] = 0;
            g[r-i-1][r+j] = 0;
        }
    }
    
    // Print 2d array from the table
    for(i=0;i<(2*r);i++){
        for(j=0;j<(2*r);j++){
		
            if(g[i][j]==1){
                textcolor(BRIGHT, bgColor, fgColor);	
                printf(" ");    
            }else{
                textcolor(BRIGHT, fgColor, bgColor);	
                printf(" ");
            }
        }
        textcolor(RESET, fgColor, bgColor);
        printf("\n");
    }
    
    textcolor(RESET, WHITE, BLACK);	
}
*/

void drawDonut2(int fgColor, int  bgColor, int d){
    int  i=0, j=0;
    
    // Method 2 : Using Circle Equation x^2+y^2 < r^r (Mathematical method)
    
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            
            int x = i-(d/2);
            int y = j-(d/2);
            
            if ((x*x + y*y) <= (d*d)/16){
                // Within Smaller Circle
                textcolor(BRIGHT, fgColor, bgColor);	
                
            }else if((x*x + y*y) <= (d*d)/4){
                // Within Outer Circle
                textcolor(BRIGHT, bgColor, fgColor);	
                
            }else{
                // Outside the Circle
                textcolor(BRIGHT, fgColor, bgColor);	
                
            }
            printf(" ");    
        }
        textcolor(RESET, fgColor, bgColor);
        printf("\n");
    }
    
    textcolor(RESET, WHITE, BLACK);	
}

void drawChecker(int fgColor, int bgColor, int s){
    
    int i, j, k=0;  
    int grid = 8;  // 8x8 boxes
	
    for(i=0;i<(s*grid);i++){
        
        k = ((i%8)==0)? 1-k : k ;  // Change flag for every 8 rows
        
        for(j=0;j<(s*grid);j++){
            
            k = ((j%8)==0)? 1-k : k ;  // Change flag for every 8 column
        
            if(k==1){ 
                textcolor(BRIGHT, fgColor, bgColor);	
            }else{
                textcolor(BRIGHT, bgColor, fgColor);
            }   
            
            printf(" "); 
        }
        
      textcolor(RESET, fgColor, bgColor);
      printf("\n");

    }
    
    textcolor(RESET, WHITE, BLACK);	
}


int detectColor(char* str){
    // Read char input and return suitable int constant
    
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
