
#include <stdio.h>

typedef struct _{
	int i;
	float f;
}newtype;

void update_newtype(newtype *);
void print_newtype(newtype);

int main(){
	newtype var1;

	update_newtype(&var1);
	print_newtype(var1);
	return 0;
}

void update_newtype(newtype * p){

	printf("input int: ");
	scanf("%d", &(p -> i));
	printf("input float: ");
	scanf("%f", &(p -> f));

	// just to show that dereferencing and using dot operator works
	printf("%d  ---- %f\n", (*p).i, (*p).f);

}
 
void print_newtype(newtype var){
	printf("i = %d -- f = %f\n", var.i, var.f);
}

