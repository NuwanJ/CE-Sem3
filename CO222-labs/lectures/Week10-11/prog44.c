// is this program "valid"?

#include <stdio.h>

int main(){
	float i = 10, *j;
	void *k = &i;
	j = k;
	printf("%f\n",*j);
	return 0;
}



