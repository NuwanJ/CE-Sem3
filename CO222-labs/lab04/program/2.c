/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main()
{
    
    char str1[15];
    char str2[15];
    int ret;
    
    //strcpy(str1, "abcdef");
    //strcpy(str1, "ABCDEF");
    
	strcpy(str1, "a");
   strcpy(str1, "A");
        
	ret  = strncmp(str1, str2, 1);
    
    printf("ret = %d\n", ret);
    
    if(ret<0){
        printf("str1 is less than str2\n");

    }else if (ret>0){
        printf("str2 is less than str1\n");

    }else{
        printf("str1 is equal to str2\n");

    }
    
    return 0;
}
