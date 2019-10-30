#include <stdio.h>

void xputs(const char * str);

int myfunc(int x, int y) {
	printf("myfunc(%d, %d)\n", x, y);
	return x + y + 8;
}

int callMyFunc(int x, int y);

int main() {
	
	const char * str = "ISEL - LEIC - PI";
	
	puts(":: BEGIN ::");
	puts(str);
	xputs(str);
	puts(":: END ::");
	
	puts("");
	
	int res = callMyFunc(3, 4);
	printf("myFunc(3, 4) returned %d\n", res);
	
	return 0;
}
