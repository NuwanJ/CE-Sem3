<<<<<<< HEAD
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int isPrime(int n){
    // n is a prme number if and only if it is divisible by 1 and itself
    
    int p=1; // consider n as a prime number
    
    if (n<2){
       p=0;
        
    }else if(n==2){
        p=1;
    
    }else{
        for(int i=2;i<n;i++){
            // all numbers between 1 and n-1
            // TODO: skip multipliers of 2,3

            if(n%i == 0){
                // not a prime
                p=0;
                break;
            }
        }
    }
    
    return p;
}

int main() {
    
    int a=0, b =0;
    int sum=0;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    int min = (a<=b)? a:b;
    int max = (a<=b)? b:a;
    
    for(int i=min;i<=max;i++){
        //printf("%d ",i);
        
        if(isPrime(i)){
            sum = sum + i;
            //printf(" prime");
        }
               
        //printf("\n");
    }
    
    printf("%d\n", sum);
    
    return 0;
}
=======
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int isPrime(int n){
    // n is a prme number if and only if it is divisible by 1 and itself
    
    int p=1; // consider n as a prime number
    
    if (n<2){
       p=0;
        
    }else if(n==2){
        p=1;
    
    }else{
        for(int i=2;i<n;i++){
            // all numbers between 1 and n-1
            // TODO: skip multipliers of 2,3

            if(n%i == 0){
                // not a prime
                p=0;
                break;
            }
        }
    }
    
    return p;
}

int main() {
    
    int a=0, b =0;
    int sum=0;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    int min = (a<=b)? a:b;
    int max = (a<=b)? b:a;
    
    for(int i=min;i<=max;i++){
        //printf("%d ",i);
        
        if(isPrime(i)){
            sum = sum + i;
            //printf(" prime");
        }
               
        //printf("\n");
    }
    
    printf("%d\n", sum);
    
    return 0;
}
>>>>>>> 53b5541140fc0bcb1509e1d014645ed226940d97
