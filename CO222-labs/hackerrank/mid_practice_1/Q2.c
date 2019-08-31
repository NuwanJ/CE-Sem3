<<<<<<< HEAD
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main() {
    
    int a=0,b=0,c=0,d=0;
    
    float delta = 0;
    float root1=0, root2=0;
    float x1=0, x2=0;
    
    scanf("%d %d %d %d", &a, &b, &c,&d);
    
    // format according to the equation
    a = a;
    b = b;
    c = c - d;

    delta  =  (b*b) - (4*a*c);  // delta =  b^2 - 4ac
    
    //printf("a=%d b=%d c=%d     delta=%f \n", a, b, c, delta);
    
    
    // ax^2 + bx + c = 0
    // x = -b/2a  +- sqrt(b^2 - 4ac) / 2a
    

    if(delta > 0){
        // two real roots
        
        root1 = ((-1*b) + sqrt(delta))/(2*a);
        root2 = ((-1*b) - sqrt(delta))/(2*a);
       
        x1 = (root1<root2)? root1 : root2;
        x2 = (root1>root2)? root1 : root2;
        
        printf("%.3f %.3f\n", x1, x2); //    sqrt j#$%  =%.3f  (sqrt(delta)/(2*a))
        
        
    }else if (delta == 0){
        // one real root
        
        x1 = (-1*b)*1.0/(2*a);
        printf("%.3f\n", x1);
        
        
    }else if (delta < 0){
        // complex roots
        float real =  (-1*b*1.0/(2*a));
        float imag  = (sqrt(-1*delta)/(2*a));
        
        
        if(real==0){
             if(imag < 0){
                 printf("%.3fi %.3fi\n",  -1*imag, imag);  
             }else{
                 // - imag
                 printf("%.3fi %.3fi\n",  imag, -1*imag);  
             }
			 
        }else if(imag > 0){
            printf("%.3f-%.3fi %.3f+%.3fi\n",  real, imag, real, imag);    
            

        }else{
            // - imag value
            imag = imag* -1.0;
            printf("%.3f-%.3fi %.3f+%.3fi\n", real, imag, real, imag);
            
        }
        //printf("real = %.3f  complex = %.3f\n", real, imag); 
    }
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
int main() {
    
    int a=0,b=0,c=0,d=0;
    
    float delta = 0;
    float root1=0, root2=0;
    float x1=0, x2=0;
    
    scanf("%d %d %d %d", &a, &b, &c,&d);
    
    // format according to the equation
    a = a;
    b = b;
    c = c - d;

    delta  =  (b*b) - (4*a*c);  // delta =  b^2 - 4ac
    
    //printf("a=%d b=%d c=%d     delta=%f \n", a, b, c, delta);
    
    
    // ax^2 + bx + c = 0
    // x = -b/2a  +- sqrt(b^2 - 4ac) / 2a
    

    if(delta > 0){
        // two real roots
        
        root1 = ((-1*b) + sqrt(delta))/(2*a);
        root2 = ((-1*b) - sqrt(delta))/(2*a);
       
        x1 = (root1<root2)? root1 : root2;
        x2 = (root1>root2)? root1 : root2;
        
        printf("%.3f %.3f\n", x1, x2); //    sqrt j#$%  =%.3f  (sqrt(delta)/(2*a))
        
        
    }else if (delta == 0){
        // one real root
        
        x1 = (-1*b)*1.0/(2*a);
        printf("%.3f\n", x1);
        
        
    }else if (delta < 0){
        // complex roots
        float real =  (-1*b*1.0/(2*a));
        float imag  = (sqrt(-1*delta)/(2*a));
        
        
        if(real==0){
             if(imag < 0){
                 printf("%.3fi %.3fi\n",  -1*imag, imag);  
             }else{
                 // - imag
                 printf("%.3fi %.3fi\n",  imag, -1*imag);  
             }
			 
        }else if(imag > 0){
            printf("%.3f-%.3fi %.3f+%.3fi\n",  real, imag, real, imag);    
            

        }else{
            // - imag value
            imag = imag* -1.0;
            printf("%.3f-%.3fi %.3f+%.3fi\n", real, imag, real, imag);
            
        }
        //printf("real = %.3f  complex = %.3f\n", real, imag); 
    }
    return 0;
}


>>>>>>> 53b5541140fc0bcb1509e1d014645ed226940d97
