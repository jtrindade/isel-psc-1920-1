#include <stdio.h>

int items[5] = { 10, 11, 12, 13, 14 };

struct student {
	int number;
	char name[128];
};

struct student st = { 19723, "Joao Trindade" };

int main() {
	
	/*
	int val = 3;
	
	int data[3] = { 100, 101, 102 };

	printf("items[0] : %p\n", &items[0]);
	printf("items[1] : %p\n", &items[1]);
	printf("items[2] : %p\n", &items[2]);
	printf("items[3] : %p\n", &items[3]);
	printf("items[4] : %p\n\n", &items[4]);
	
	printf("val : %p\n\n", &val);
	
	printf("data[0] : %p\n", &data[0]);
	printf("data[1] : %p\n", &data[1]);
	printf("data[2] : %p\n", &data[2]);
	*/

	/*
	int a = 5;
	int b = 8;
	
	int *pp = &a;
	
	printf("the address of a is: %p\n", &a);
	printf("the address of b is: %p\n", &b);
	
	printf("pp contains the address: %p\n", pp);
	printf("pp points to the value: %d\n", *pp);
	
	printf("switching pp to point to b\n");
	pp = &b;
	
	printf("pp contains the address: %p\n", pp);
	printf("pp points to the value: %d\n", *pp);
	*/
	
	struct student st1 = { 1000, "Afonso Henriques" };
	struct student st2 = st1;
	
	printf("st1.number : %d\n", st1.number);
	printf("st2.number : %d\n", st2.number);
	
	st2.number = 1234;
	
	printf("st1.number : %d\n", st1.number);
	printf("st2.number : %d\n", st2.number);

	struct student *pst1 = &st1;
	struct student *pst2 = pst1;
	
	(*pst2).number = 2222;
	
	printf("st1.number : %d\n", st1.number);
	printf("st2.number : %d\n", st2.number);
	
	return 0;

}

