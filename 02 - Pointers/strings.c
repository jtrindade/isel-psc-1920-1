#include <stdio.h>

char str2[5] = { 'I', 'S', 'E', 'L', '\0' };
char str3[4] = "ABC";
char str[17] = "ISEL - LEIC - PI";

void xputs(const char * p) {
	while (*p != '\0') {
		putchar(*p);
		++p;
	}
}

unsigned int xstrlen(const char * p) {
	unsigned int len = 0;
	while (*p != '\0') {
		++len;
		++p;
	}
	return len;
	const char* cp;
}

unsigned int xstrlen2(const char * p) {
	const char *cp;
	for (cp = p; *cp; ++cp);
	return cp - p;
}

int main() {
	
	const char *p = str;
	
	int len = xstrlen2(p);
	
	printf("len: %d\n", len);

	return 0;
}
