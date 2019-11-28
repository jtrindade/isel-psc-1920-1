#include "xmalloc.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * TEXT = "ISEL - LEIC - PSC";

int main() {
	
	size_t textLen = strlen(TEXT);
	
	char * copiedText = (char *)malloc(textLen + 1);

	strcpy(copiedText, TEXT);
	
	puts(copiedText);

	free(copiedText);
	
	return 0;
}
