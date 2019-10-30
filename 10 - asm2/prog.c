#include <stdio.h>

struct X {
	int i1;
	char c2;
};

struct example {
	unsigned int number;
	float rate;
	char text[8];
	int id;
	short category;
};

int func1();
int func2(int a);
int func3(int a, int b);                   // sum
int func4(const char * str);               // strlen clone
int func5(int * items, unsigned numItems); // index
int func6(struct example * pdata);         // getId


int main() {
	
	int res1 = func1();
	printf("res1: %d\n", res1);

	int res2 = func2(3);
	printf("res2: %d\n", res2);

	int res3 = func3(3, 5);
	printf("res3: %d\n", res3);

	int res4 = func4("ISEL - LEIC - PSC");
	printf("res4: %d\n", res4);

	int items[] = { 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007 };
	int res5 = func5(items, 3);
	printf("res5: %d\n", res5);

	struct example data = { 123, 1.0, "ISEL", 8888, 20 };
	int res6 = func6(&data); 
	printf("res6: %d\n", res6);
	
	printf("sizeof(X): %lu\n", sizeof (struct X));

	return 0;
}
