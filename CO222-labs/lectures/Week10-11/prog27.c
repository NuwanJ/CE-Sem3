/* C - Variable Scopes and Lifetime

   See https://www.tutorialspoint.com/cprogramming/c_scope_rules.htm

 	1. Local variables (inside a function or block)
	2. Global variables (outside of all functions)
	3. Formal parameters (in the definition of functions) 
	4. Extern variables
*/

/*  Local Variables 

	Scope: within the block they are declared
	Lifetime: the lifetime of the function inside which they are declared

		Lifetime of a function is from the time it is called, until its return
*/

#include <stdio.h>
 
int main(){

  /* local variable declaration */
  int a, b;
  int c;
 
  /* actual initialization /definition */
  a = 10;
  b = 20;
  c = a + b;
 
  printf ("value of a = %d, b = %d and c = %d\n", a, b, c);

  {
	int a = 100;
	printf("another a = %d\n", a);
  }

  return 0;
}
