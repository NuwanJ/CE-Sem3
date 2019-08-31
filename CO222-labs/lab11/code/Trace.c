// Week10_Trace.c
// Tracing exercises
#include <stdio.h>

void mystery1(int);
void mystery2(int);

int main(void) {
	int num;

	printf("Enter positive intenger: ");	// integer ?
	scanf("%d", &num);

	printf("Output of mystery1(%d): ", num);
	mystery1(num);
	printf("\n");

	printf("Output of mystery2(%d): ", num);
	mystery2(num);
	printf("\n");

	return 0;
}

void mystery1(int n) {
	if (n>0) {
		printf("%d", n%10);
		mystery1(n/10);
	}
}

void mystery2(int n) {
	if (n>0) {
		mystery2(n/10);
		printf("%d", n%10);
	}
}

/*
*******************************
* Trace Tree                  *
*******************************


mystery1(3902){
	print(2);
	mystery1(390){
		print(0);
		mystery1(39){
			print(9);
			mystery1(3){
				print(3);
				mystery1(0){}
			}
		}
	]
}

Result : 2093


mystery2(3902){
	mystery2(390){
		mystery2(39){
			mystery2(3){
				mystery2(0){
				
				}
				print(3);
			}
			print(9);
		}
		print(0);
	}
	print(2);
}





*/



