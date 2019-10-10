#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

void f1(char * ptr) {
	printf("sizeof (char *): %d\n", sizeof ptr);
}

void f2(char str[]) {
	printf("sizeof (char[]): %d\n", sizeof str);
}


int main(int argc, char * argv[]) {
	
	long double * ptr;
	const char * s = "iselleicpsc2019";
	char str[] = "iselleicpsc2019";
	
	bool b = true;
	
	char c = 'a';
	unsigned char uc = 34;
	
	signed short int s1 = -21;
	short s2 = -21;
	
	int i = ~0;
	
	unsigned long l = 0xDEADBEEF;
	
	float f = 0.5;
	
	double d = 1.45e5;
	
	printf("sizeof (bool): %d\n", sizeof (bool));
	printf("sizeof (char): %d\n", sizeof (char));
	printf("sizeof (short): %d\n", sizeof (short));
	printf("sizeof (int): %d\n", sizeof (int));
	printf("sizeof (long): %d\n", sizeof (long));
	printf("sizeof (long long): %d\n", sizeof (long long));
	printf("sizeof (int8_t): %d\n", sizeof (int8_t));
	printf("sizeof (int16_t): %d\n", sizeof (int16_t));
	printf("sizeof (int32_t): %d\n", sizeof (int32_t));
	printf("sizeof (int64_t): %d\n", sizeof (int64_t));
	printf("sizeof (float): %d\n", sizeof (float));
	printf("sizeof (double): %d\n", sizeof (double));

	puts(s);
	printf("sizeof (string): %d\n", sizeof s);
	puts(str);
	printf("sizeof (string): %d\n", sizeof str);
	printf("sizeof (long double *): %d\n", sizeof ptr);
	
	f1(s);
	f2(str);
	
	return 0;
}
