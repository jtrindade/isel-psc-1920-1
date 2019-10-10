#include <stdio.h>
#include <math.h>

// bitfields
struct fbits {
	unsigned m : 23;
	unsigned e :  8;
	unsigned s :  1;
};

// campos sobrepostos
union number {
	float        f;
	unsigned     u;
	struct fbits b;
};

int main() {
	union number num;
	num.f = NAN;

	printf(
		"float %e : %08X : s=%u e=%u m=%06X",
		num.f,
		num.u,
		num.b.s,
		num.b.e,
		num.b.m
	);
	
	return 0;
}
