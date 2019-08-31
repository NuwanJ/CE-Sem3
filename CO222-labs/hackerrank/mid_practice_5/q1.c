#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    
    int n=0;
    printf("Enter N:");
    scanf("%d", &n);
    
    printf("\n");
    
    for (int i=0;i<n;i++){
        // print spaces
        for(int j=0;j<n-1-i;j++){
            printf(" ");
        }
        
        // print *
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        
        printf("\n");
    }
    
    
    
    return 0;
}