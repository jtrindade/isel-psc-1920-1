#include <stdio.h>
#include <dlfcn.h>

typedef int (*addi_func)(int a, int b);

int main() {
	printf("Starting prog...\n");

	void * libcalc = dlopen("./libcalc.so", RTLD_NOW | RTLD_GLOBAL);
	if (libcalc == NULL) {
		fprintf(stderr, "%s\n", dlerror());
		return -1;
	}

	addi_func addi;
	int (*muli)(int a, int b);
	int * memi;

	*(void**)&addi = dlsym(libcalc, "addi");
	*(void**)&muli = dlsym(libcalc, "muli");
	memi = dlsym(libcalc, "memi");
	
	int a = 3;
	int b = 4;
	
	int s = addi(a, b);
	int p = muli(a, b);
	
	*memi = s;
	
	printf("a + b : %d\n", s);
	printf("a * b : %d\n", p);
	
	printf("memi  : %d\n", *memi);

	dlclose(libcalc);
	
	return 0;
}
