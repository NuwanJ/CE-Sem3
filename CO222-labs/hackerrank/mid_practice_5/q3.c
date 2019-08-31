#include<stdio.h>
#include<ctype.h>

#define BUFF_SIZE 256

int isPalindrome(char s[]);


int main(){
	char s[BUFF_SIZE];

	printf("Enter string:\n");
	fgets(s, BUFF_SIZE, stdin);	

	if (isPalindrome(s)){
		printf("Yes, it is a palindrome.\n");
	}else{
		printf("No, it is not a palindrome.\n");
	} 	

	return 0;
}


int isPalindrome(char s[]){
    
    char t[BUFF_SIZE];
    int len=0;
    
    // fill an array with only required once
    for(int i=0;s[i]!='\0';i++){
       if(isalpha(s[i])){
           t[len]= tolower(s[i]);
           //printf("%c \n", t[len]);
           len++;
       }
    }
    
    for(int i=0;i<len/2;i++){
        if(t[i]!=t[len-i-1]){
            //printf("%c %c\n", t[i],  t[len-i-1]);
            return 0;
        }else{
            
        }
    }
    return 1;
}