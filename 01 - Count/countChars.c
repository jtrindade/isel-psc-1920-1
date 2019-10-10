#include <stdio.h>

int main() {
	int c, nchars;
	for (nchars = 0; (c = getchar()) != EOF; ++nchars);
	printf("%d\n", nchars);
	return 0;
}
