#include <stdio.h>

int main() {
	int total = 0;
	int c;
	for (;;) {
		c = getchar();
		if (c == EOF) break;
		total += 1;
	}
	printf("%d\n", total);
	return 0;
}
