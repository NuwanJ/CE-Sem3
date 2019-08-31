<<<<<<< HEAD
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    
    char in[256] = {};
    int i=0, num=0, sign=1;
    int sum=0;
    
    scanf("%s", &in);
    //printf("\n%s\n", in);
    
    while(in[i]!='\0'){
        
        if(in[i]=='"'){
            i++;
            
            // get the sign
            if(in[i]=='-'){
                sign=-1;
                i++;
            }
            
            while(in[i]!='"'){
                num = num*10 + in[i]-'0';
                //printf("%d \n", num);
                i++;
            }
            
            sum+= sign*num;
            num=0;
            sign=1;
        }
        i++;
    }
    
    printf("%d\n",sum);
    return 0;
=======
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    
    char in[256] = {};
    int i=0, num=0, sign=1;
    int sum=0;
    
    scanf("%s", &in);
    //printf("\n%s\n", in);
    
    while(in[i]!='\0'){
        
        if(in[i]=='"'){
            i++;
            
            // get the sign
            if(in[i]=='-'){
                sign=-1;
                i++;
            }
            
            while(in[i]!='"'){
                num = num*10 + in[i]-'0';
                //printf("%d \n", num);
                i++;
            }
            
            sum+= sign*num;
            num=0;
            sign=1;
        }
        i++;
    }
    
    printf("%d\n",sum);
    return 0;
>>>>>>> 53b5541140fc0bcb1509e1d014645ed226940d97
}