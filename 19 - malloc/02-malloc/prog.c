#include "xmalloc.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * TEXT = "ISEL - LEIC - PSC";

int main() {
	xmalloc_init();
	
	size_t textLen = strlen(TEXT);
	
	char * copiedText = (char *)xmalloc(textLen + 1);

	strcpy(copiedText, TEXT);
	
	puts(copiedText);

	xfree(copiedText);
	
	return 0;
}
