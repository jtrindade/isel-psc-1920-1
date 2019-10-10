#include <stdio.h>

int data[5] = { 10, 11, 12, 13, 14 };

char str[5] = "ISEL";

char str2[4] = { 'L', 'E', 'I', 'C' };
char str3[4] = "XPTO";

int main() {
	for (int i = 0; i < 5; ++i) {
		printf("%d\n", data[i]);
	}
	for (int j = 0; j < 4; ++j) {
		printf("%c\n", str[j]);
	}
	puts(str);
	puts(str2);
	return 0;
}
