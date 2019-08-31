/* C - Variable Scopes and Lifetime

   See https://www.tutorialspoint.com/cprogramming/c_scope_rules.htm

 	1. Local variables (inside a function or block)
	2. Global variables (outside of all functions)
	3. Formal parameters (in the definition of functions) 
	4. Extern variables
*/

/*  Global Variables 
	
	Scope: Global
	Lifetime: The whole time of the program execution

*/

#include <stdio.h>
 
/* global variable declaration */
int g;
 
int main () {

  /* local variable declaration */
  int a, b;
 
  /* actual initialization */
  a = 10;
  b = 20;
  g = a + b;
 
  printf ("value of a = %d, b = %d and g = %d\n", a, b, g);
 
  return 0;
}

