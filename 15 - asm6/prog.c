#include <stdio.h>
#include <stdint.h>

struct xjmp_buf {
	uint64_t rbx;
	uint64_t r12;
	uint64_t r13;
	uint64_t r14;
	uint64_t r15;
	uint64_t rbp;
	uint64_t rsp;
	uint64_t rip;
};

int xsetjmp(struct xjmp_buf *env);
void xlongjmp(struct xjmp_buf *env, int retval);

struct xjmp_buf env;

void baz(int x) {
	puts("         baz: begin");
	printf("         x: %d\n", x);
	if (x != 0) {
		xlongjmp(&env, 9876);
		puts("         baz: THIS WILL NEVER APPEAR!");
	}
	puts("         baz: end");
}

void bar(int x) {
	puts("      bar: before call");
	baz(x);
	puts("      bar: after call");
}

void foo(int x) {
	puts("   foo: before call");
	bar(x);
	puts("   foo: after call");
}

int main() {
	
	puts("main: before call");
	foo(0);
	puts("main: after call");

	puts("");

	int res = xsetjmp(&env);
	if (res == 0) {
		puts("main: before call");
		foo(1);
		puts("main: after call");
	} else {
		printf("main: elsewhere with %d\n", res);
	}
	
	return 0;
}