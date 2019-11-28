
#include <stdio.h>
#include "f2.h"
#include "f3.h"

int var_f1_a = 8;

int func_f1_f(int a) {
	return a + var_f1_a;
}

int main() {
	int res1 = func_f1_f(7);
	int res2 = func_f2_m(2, 3);
	int res3 = func_f3_p();
	
	printf("res1: %d\n", res1);
	printf("res2: %d\n", res2);
	printf("res3: %d\n", res3);

	printf("f3 var: %d\n", var_f3_h);
	
	return 0;
}
