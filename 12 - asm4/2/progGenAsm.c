#include <stdio.h>
#include <string.h>
#include <limits.h>

int numbers[] = { 7, -21, 35, -99, 0, -1, 23, 77, 201, -3 };

const char * text[] = { "ISEL", "LEIC", "PSC" };

const void * xfind(
		const void * firstItem,
		size_t numItems,
		size_t dimItem,
		int (*cmp)(const void *, const void *),
		const void * ref);

int isIntGreaterThan(const void * pItem, const void * pRef) {
	int item = *((const int *)pItem);
	int ref  = *((const int *)pRef);
	return item > ref;
}

int isStrEarlierThan(const void * pItem, const void * pRef) {
	const char * item = *((const char * *)pItem);
	const char * ref  = *((const char * *)pRef);
	return strcmp(item, ref) < 0;
}

int isStrShorterThan(const void * pItem, const void * pRef) {
	const char * item = *((const char * *)pItem);
	int ref  = *((int *)pRef);
	return strlen(item) < ref;
}

int isStrEarlierThanAlt(const void * pItem, const void * pRef) {
	const char * item = *((const char * *)pItem);
	const char * ref  = (const char *)pRef;
	return strcmp(item, ref) < 0;
}
int main() {
	
	int refInt = 50;
	const int * pResInt =
		xfind(numbers, 10, sizeof(numbers[0]), isIntGreaterThan, &refInt);
	
	const char * refStr1 = "K";
	const char * const * pResStr1 =
		xfind(text, 3, sizeof(text[0]), isStrEarlierThan, &refStr1);
	
	int refStr2 = 4;
	const char * const * pResStr2 = 
		xfind(text, 3, sizeof(text[0]), isStrShorterThan, &refStr2);
	
	const char * const * pResStr3 =
		xfind(text, 3, sizeof(text[0]), isStrEarlierThanAlt, refStr1);
	
	printf("resInt: %d\n",  *pResInt);
	printf("resStr1: %s\n", *pResStr1);
	printf("resStr2: %s\n", *pResStr2);
	printf("resStr3: %s\n", *pResStr3);
	
	return 0;
}
