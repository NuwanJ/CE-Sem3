/******************************************************************************

    Lab3 - Program2
    Program invert the given image colors
    E/15/140
	 Last update : 2018/02/22

*******************************************************************************/

#include <stdio.h>

int main ()
{

    int cols = 0, rows = 0;
    int colsA = 0;
    int i=0,j=0;

    int R=0,G=0,B=0, garbage;

    int reader = 0;

    reader = scanf ("%d %d", &cols, &rows);
    
    printf("%d %d\n", cols, rows);

    if (reader == 2){

        // Need to process how many columns we need to read from stdin
        colsA = cols*3;
        while (colsA % 4 != 0) colsA++;
    
        //printf ("Input Columns: %d Rows: %d\n", cols, rows);
        //printf ("Actual Columns: %d Rows: %d\n", colsA, rowsA);


        for (i=0;i<rows;i++){
                
            for (j=0;j<colsA;j++){
                    
                if(j<cols*3){
                    // Code to invert
                    scanf("%d %d %d", &R,&G,&B);
                    printf("%d %d %d\n", 255-R, 255-G, 255-B);
                    j += 2;	// For column counter
                           
                }else{
                    // Empty cols
                    scanf("%d", &garbage);
                    printf("0\n");
                }
            }
        }
    }else{
      // Invalid input ? is this required for this program ???
    }

  	return 0;
}
