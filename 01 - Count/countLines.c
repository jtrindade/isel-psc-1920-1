#include <stdio.h>

int main() {
	int pc = '\n', c, nlines;
	for (nlines = 0; (c = getchar()) != EOF; ) {
		if (c == '\n') {
			nlines += 1;
		}
		pc = c;
	}
	if (pc != '\n') {
		nlines += 1;
	}
	printf("%d\n", nlines);
	return 0;
}
