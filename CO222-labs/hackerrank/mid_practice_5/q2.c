#include<stdio.h>

#define BUFF_SIZE 256

void reverseString(char s[]);

int main(){
	char s[BUFF_SIZE];

	printf("Enter string\n");
	
	/* fgets() reads in at most one less than size characters  from
	stream and stores them into the buffer pointed to by s. Reading
	stops  after an   EOF or a newline. If a newline is read, it is 
	stored  into  the  buffer.  A   terminating null byte ('\0') is
	stored after the last character in the buffer. 
	*/
	fgets(s, BUFF_SIZE, stdin);

	reverseString(s);
	
	return 0;
}

void reverseString(char s[]){
    
    int count = 0;
    for(int i=0;s[i]!='\0'&& s[i]!='\n' ;i++){
        count++;
        //printf(" %c\n", s[i]);
    }
    
    for(int i=count;i>=0;i--){
        count++;
        if(s[i]!='\n'){
            printf("%c", s[i]);
        }
    }
    
    printf("\n");
    
}



