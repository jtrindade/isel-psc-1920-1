#include "xmalloc.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * TEXT1 = "ISEL - LEIC - PSC";
const char * TEXT2 = "Programacao em Sistemas Computacionais";

int main() {
	xmalloc_init();
	
	size_t text1Len = strlen(TEXT1);
	size_t text2Len = strlen(TEXT2);
	
	char * copiedText1 = (char *)xmalloc(text1Len + 1);
	char * copiedText2 = (char *)xmalloc(text2Len + 1);

	strcpy(copiedText1, TEXT1);
	strcpy(copiedText2, TEXT2);
	
	puts(copiedText1);
	puts(copiedText2);

	xfree(copiedText1);
	xfree(copiedText2);
	
	return 0;
}
