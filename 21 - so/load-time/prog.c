#include <stdio.h>

#include "calc.h"

int main() {
	printf("Starting prog...\n");
	
	int a = 3;
	int b = 4;
	
	int s = addi(a, b);
	int p = muli(a, b);
	
	memi = s;
	
	printf("a + b : %d\n", s);
	printf("a * b : %d\n", p);
	
	printf("memi  : %d\n", memi);
	
	return 0;
}
