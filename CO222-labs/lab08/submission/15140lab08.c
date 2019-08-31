/**************************************************************
	CO222 - Lab 08 

	Author : Jaliyagoda A.J.N.M (E/15/140)
	Last Update: 26/05/2018

***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

	int cpl=0;											// characters per line 
	char fileName[64] = {};
	char tempC=0;

	FILE *fp;
	
	if(argc<3){											
		// ERROR: No enough arguments
		printf("Usage: %s <width> <input-file>\n", argv[0]);
		return -1;

	}else{
		// Obtain the file name and width
		cpl=atoi(argv[1]);
		strcpy(fileName, argv[2]);

		if(fp==NULL){
			// ERROR: can't open the file	
			printf("\n");									
			return -1;
		
		}else{

			char str[999];
			int counter=0, wordSize=0;
			int maxWordSize=0; 

			// ** calculate maximum length of a word  ***************************************************

			fp = fopen(fileName, "r");
			
			while (fscanf(fp, "%s", str)!=EOF){
				wordSize = strlen(str);
				maxWordSize = (wordSize > maxWordSize) ? wordSize : maxWordSize;
			}

			if(cpl<maxWordSize){
				// ERROR: width not enough
				printf("Word lenght must be less than screen width\n");
				return -1;
			}

			// ** Print the paragraph ******************************************************************

			rewind(fp);

			while (fscanf(fp, "%s%c", str, &tempC)!=EOF){
				wordSize = strlen(str);

				if (counter + wordSize > cpl){

					if (tempC=='\n'){
						printf("\n%s\n", str);
						counter = 0;
					}else{
						printf("\n%s ", str);
						counter = wordSize + 1;
					}
					
				}else if (tempC=='\n'){
					printf("%s\n", str);
					counter = 0;

				}else{
					printf("%s ", str);
					counter = counter + wordSize + 1;
				}
			}
			fclose(fp);
		}
	}
	return 0;
}




