#include <stdio.h>

// a1 .. a6 : rdi, rsi, rdx, rcx, r8, r9
// a7 .. a8 : stack
int func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

int main() {
	
	int res = func(1, 2, 3, 4, 5, 6, 7, 8);
	
	printf("res: %d\n", res);
	
	return 0;
}
