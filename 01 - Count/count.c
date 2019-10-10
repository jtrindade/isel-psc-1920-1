#include <stdio.h>

int isSpace(int c) {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main() {
	int pc = ' ', c, nwords;
	for (nwords = 0; (c = getchar()) != EOF; ) {
		if (!isSpace(c) && isSpace(pc)) {
			nwords += 1;
		}
		pc = c;
	}
	printf("%d\n", nwords);
	return 0;
}
