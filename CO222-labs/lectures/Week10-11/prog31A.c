/* C - Variable Scopes and Lifetime

   See https://www.tutorialspoint.com/cprogramming/c_scope_rules.htm

 	1. Local variables (inside a function or block)
	2. Global variables (outside of all functions)
	3. Formal parameters (in the definition of functions) 
	4. Extern variables
*/

/* Extern keyword (implicit) in functions 

    http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/

	Part A of a program

*/

int f1();
int f2();

int main(){
	
	f1();
	f2();
	return 0;
}
