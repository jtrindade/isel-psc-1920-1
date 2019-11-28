#include <stdio.h>

int func1() {
	int x = 0;
	return x++;
}

int func2() {
	static int x = 0;
	return x++;
}

int main() {
	int v11 = func1();
	int v12 = func1();
	int v13 = func1();
	
	int v21 = func2();
	int v22 = func2();
	int v23 = func2();
	
	printf("v11: %d; v12: %d; v13: %d\n", v11, v12, v13);
	printf("v21: %d; v22: %d; v23: %d\n", v21, v22, v23);
	
	return 0;
}