#include<stdio.h>
#include<stdlib.h>

typedef struct myobject
{
	int values[6];
	int index;
} MyObject;

MyObject* createNewObject()
{
	static MyObject* returnValue; 	// Added static keyword	
	MyObject object;
	object.index = 0;
	//object.values[2] = 35;	
	returnValue = &object;
	return returnValue;
}

int addValues(MyObject* object, int i)
{
	int var1 = 10;
	int var2 = 20;
	int var3 = 30;
	int var4 = 30;
	int var5 = 30;
	int var6 = 30;
	int var7 = 30;

	// Assign some values to the object
	//object->index = 1;
	object->values[0] = 10 + i + 2;
	object->values[1] = 20 + i + 8;
	object->values[2] = 30 + i + 4;
	object->values[3] = 30 + i + 4; // Overflow detected
	object->values[4] = 30 + i + 4; // mistake on variable naming
	object->values[5] = 30 + i + 4;

	// We havent changed var1, var2, var3 any time
	// Lets just try to print them.
	printf("We are printing the values of var1, var2 & var3.\nSince we didn't changed them they should be 10 20 & 30.\n");
	//printf("Values : %d %d %d \n", var1,var2,var3);
}

int main()
{
	int a = 10;
	MyObject* object = createNewObject();
	addValues(object, a);
	return 0;
}


