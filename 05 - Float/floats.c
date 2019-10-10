#include <stdio.h>

int main() {

	int v1 = 1234;
	int v2 = 0xabcd;
	int v3 = 0123;

	float f1 = 1.625;
	int   i1 = f1;
	float f2 = i1;
	
	printf("f1: %e\n", f1);
	printf("i1: %d\n", i1);
	printf("f2: %e\n", f2);
	
	printf("v1: %d %x %o\n", v1, v1, v1);
	
	float * pf1 = &f1;
	int * pif1 = (int*)pf1;
	int if1 = *pif1; // ler 32 bits de float como int
	
	printf("if1: 0x%08X\n", if1);
	
	return 0;
}