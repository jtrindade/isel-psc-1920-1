#include <stdio.h>

#define LOWT -5
#define HIGHT 55
#define STEPT 5

/*
const int LOWT  = -5;
const int HIGHT = 55;
const int STEPT =  5;
*/

int main() {
	
	int tc;

	for (tc = LOWT; tc < HIGHT; tc += STEPT) {
		int tf = 9.0/5 * tc + 32;\
		printf("%d C => %d F\n", tc, tf);
	}

	return 0;
}
