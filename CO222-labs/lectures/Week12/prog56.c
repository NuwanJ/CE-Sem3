// Programmer Defined Data Types
//	(1) enum   - enumerated data types
//	(2) struct - compound data types

#include <string.h>
#include <stdio.h>
/*
	student type following fields
		(1) regNo - string 10
		(2) firstName - string 50
		(3) lastName  - string 50
		(4) age	- int 
		(5) courses - 6 x string 6
*/

typedef struct student{
	char regNo[10];
	char fName[50];
	char lName[50];
	int	age;
	char courses[6][6];
	float marks[6];
} studentType;

studentType initStudent();
void printStudent(studentType);
void printStudents(studentType*, int len);

int main(){
	int count;
	studentType s1[3];

	for(count = 0; count < 3; count++){
		s1[count] = initStudent();
	}	

	for(count = 0; count < 3; count++){
		printStudent(s1[count]);
	}	

	return 0;
}


studentType initStudent(){
	studentType s;

	scanf("%s", s.regNo); //	strcpy(s.regNo,"E/15/123");
	strcpy(s.fName, "Name1");
	strcpy(s.lName, "Name2");
	s.age = 20;
	strcpy(s.courses[0],"CO221");
	strcpy(s.courses[1],"CO222");
	strcpy(s.courses[2],"CO223");
	strcpy(s.courses[3],"EM201");
	strcpy(s.courses[4],"EM313");
	strcpy(s.courses[5],"EE282");
	s.marks[0] = 0;
	s.marks[1] = 0;
	s.marks[2] = 0;
	s.marks[3] = 0;
	s.marks[4] = 0;
	s.marks[5] = 0;
	
	return s;
}

void printStudents(studentType* s, int size){
	int count, studentNo;
	
	for(studentNo = 0; studentNo < size; studentNo++){
		printf("Registration No.: %s\n", s[studentNo].regNo);
		printf("Name: %s %s\n", s.fName, s[studentNo].lName);
		printf("Age: %d\n", s.age);
		printf("Courses: ");
		for(count=0; count<6; count++){
			printf("%s ", s.courses[count]);
		}
		printf("\n");
		printf("Marks: ");
		for(count=0; count<6; count++){
			printf("%f ", s.marks[count]);
		}
		printf("\n");
	}
}

void printStudent(studentType s){
	int count;
	printf("Registration No.: %s\n", s.regNo);
	printf("Name: %s %s\n", s.fName, s.lName);
	printf("Age: %d\n", s.age);
	printf("Courses: ");
	for(count=0; count<6; count++){
		printf("%s ", s.courses[count]);
	}
	printf("\n");
	printf("Marks: ");
	for(count=0; count<6; count++){
		printf("%f ", s.marks[count]);
	}
	printf("\n");
}
