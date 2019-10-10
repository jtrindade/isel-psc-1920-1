#include <stdio.h>

struct fbits {
	unsigned m : 23;
	unsigned e : 8;
	unsigned s : 1;
};

union number {
	float        f;
	unsigned     u;
	struct fbits b;
};

int main() {
	
	float f1 = 1.625;
	int  if1 = *(int*)&f1;

	union number num;	
	num.f = 1.625;
	
	printf("if1:   0x%08X\n", if1);
	printf("num.u: 0x%08X\n", num.u);
	
	printf("fbits s: %u\n", num.b.s);
	printf("fbits e: %u\n", num.b.e);
	printf("fbits m: %06X\n", num.b.m);
	
	return 0;
}