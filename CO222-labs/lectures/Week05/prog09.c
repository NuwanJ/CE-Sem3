/* 

	mix type operations

		int / int -> / int
		float / int -> / float  -> implicit casting (int -> float)
		int / float -> / float  -> implicit casting (int -> float)

*/


int main(){

	int x = 45;
	float y = 5.5;

	printf("x / y = %f\n", x / y);  // / here is a floating point (FP) div

	printf(" x / 6 = %f\n", x / (float)6); // explicit casting 


	return 0;
}
