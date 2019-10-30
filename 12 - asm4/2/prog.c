#include <stdio.h>
#include <string.h>
#include <limits.h>

int numbers[] = { 7, -21, 35, -99, 0, -1, 23, 77, 201, -3 };

const char * text[] = { "ISEL", "LEIC", "PSC" };

int findIntGreaterThan(const int * items, size_t numItems, int ref) {
	for (int i = 0; i < numItems; ++i) {
		if (items[i] > ref) {
			return items[i];
		}
	}
	return INT_MIN;
}

const char * findStrEarlierThan(const char * items[], size_t numItems, const char * ref) {
	for (int i = 0; i < numItems; ++i) {
		if (strcmp(items[i], ref) < 0) {
			return items[i];
		}
	}
	return NULL;
}

const char * findStrShorterThan(const char * items[], size_t numItems, size_t ref) {
	for (int i = 0; i < numItems; ++i) {
		if (strlen(items[i]) < ref) {
			return items[i];
		}
	}
	return NULL;
}

int main() {
	
	int resInt = findIntGreaterThan(numbers, 10, 50);
	
	const char * resStr1 = findStrEarlierThan(text, 3, "K");
	
	const char * resStr2 = findStrShorterThan(text, 3, 4);
	
	printf("resInt: %d\n", resInt);
	printf("resStr1: %s\n", resStr1);
	printf("resStr2: %s\n", resStr2);
	
	return 0;
}
