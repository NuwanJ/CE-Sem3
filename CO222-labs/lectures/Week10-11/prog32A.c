/* C - Variable Scopes and Lifetime

   See https://www.tutorialspoint.com/cprogramming/c_scope_rules.htm

 	1. Local variables (inside a function or block)
	2. Global variables (outside of all functions)
	3. Formal parameters (in the definition of functions) 
	4. Extern variables
*/

/* Extern keyword with variables 

	Part A of a program

*/

extern int var;

int main(){
	var = 10;
	return 0;
} 
