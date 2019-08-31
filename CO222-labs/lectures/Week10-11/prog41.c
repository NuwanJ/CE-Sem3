#include <stdio.h>

int main(){
   int number;
   int number2 = 125;
   int *nptr;
   
   number = 10*15;
   nptr= &number;
   printf("nptr = %p\n",nptr);
   
   nptr++;
   printf("nptr++ = %p\n", nptr);
   printf("*nptr++= %d\n", *nptr);
   
   nptr++;
   nptr++;
   nptr += 10000; // outside of the current program memory
   
   printf("nptr = %p\n",nptr);
   printf("Number: in nptr %d\n", *nptr);   

   return 0;
}
