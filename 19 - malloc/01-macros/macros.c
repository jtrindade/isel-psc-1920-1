
#define OFFSET_OF(TYPE, FIELD) \
	((unsigned int)(unsigned long)&(((TYPE *)0)->FIELD))

int printf(const char * format, ...);

struct X {
	int a;
	double b;
	char c;
};

#define CONTAINER_OF(PTR, TYPE, FIELD) \
	((TYPE *)(((char *)PTR) - OFFSET_OF(TYPE, FIELD)))

struct X * getStructAddr(char * p) {
	return (struct X *)(p - OFFSET_OF(struct X, c));
}

int main() {
	
	unsigned int oc = OFFSET_OF(struct X, c);
	
	printf("offset(X::a) = %u\n", OFFSET_OF(struct X, a));
	printf("offset(X::b) = %u\n", OFFSET_OF(struct X, b));
	printf("offset(X::c) = %u\n", oc);

	// ==============
	
	struct X instance;
	
	char * p = &(instance.c);
	
	printf("addr(instance) = %p\n", (void *)&instance);
	
	struct X * pinstance = getStructAddr(p);

	printf("addr(instance) = %p\n", (void *)pinstance);
	
	struct X * pinstance2 = CONTAINER_OF(p, struct X, c);

	printf("addr(instance) = %p\n", (void *)pinstance2);
	
	return 0;
}