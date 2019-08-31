<<<<<<< HEAD
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    
    int n = 0;
    int fib[1000]={0};
    fib[0] = 1;
    fib[1] = 1;
    int prod = 1;
    
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
            
        if(i==0){
            fib[0] = 1;
        }else if(i==1){
            fib[1] = 1;
            
        }else{
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        prod = prod*fib[i];
        //printf("%d ", fib[i]);
    }
    
    printf("%d", prod);
    

    
    
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
    
    int n = 0;
    int fib[1000]={0};
    fib[0] = 1;
    fib[1] = 1;
    int prod = 1;
    
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
            
        if(i==0){
            fib[0] = 1;
        }else if(i==1){
            fib[1] = 1;
            
        }else{
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        prod = prod*fib[i];
        //printf("%d ", fib[i]);
    }
    
    printf("%d", prod);
    

    
    
    return 0;
>>>>>>> 53b5541140fc0bcb1509e1d014645ed226940d97
}