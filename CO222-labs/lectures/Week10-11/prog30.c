/* C - Global vs. Local Variables

		Initialization

*/

#include <stdio.h>

int a;

int main () {

  int b;

  printf("uninitialized global variable a = %d\n", a); // will print 0 (global vars are automatically initialized - int/float/double to 0, char to '\0' and pointer to NULL

  printf("uninitialized local  variable b = %d\n", b); // will print *garbage*

  return 0;
}
