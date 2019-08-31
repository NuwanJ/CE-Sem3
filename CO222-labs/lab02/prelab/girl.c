
#include <stdio.h>
#include <string.h>

int main(){

	char hi[4][3] = {"hi\0", "hI\0", "Hi\0", "HI\0"};

  	char data[3];

	scanf("%s", &data);

	for(int i=0;i<4;i++){
		if(strcmp(data, hi[i])==0){
			printf("I have a boyfriend!\n");
			break;
		}
	}

	/*
	// Only for debugging
	printf(">> %s\n", hi[0]);
	printf("%s %d\n", hi[0],  strcmp(data, hi[0]));
	printf("%s %d\n", hi[1],  strcmp(data, hi[1]));
	printf("%s %d\n", hi[2],  strcmp(data, hi[2]));
	printf("%s %d\n", hi[3],  strcmp(data, hi[3]));
	*/
	return 0;
}
