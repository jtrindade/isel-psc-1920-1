int printf(const char * fmt, ...);

#define PLUS(A, B) ((A) + (B))

#define TIMES(A, B) ((A) * (B))

#define OPER(A, B) ((A) + (B) * (B))

int main() {
	
	int c = PLUS(3, 4) * 3;  // int c = ((3) + (4)) * 3;
	
	printf("%d\n", c);

	int d = TIMES(3, 3 + 4);    // int d = ((3) * (3 + 4));
	
	printf("%d\n", d);
	
	int x = 3;
	int f = OPER(2, ++x);  // !!! ++x é avaliado duas vezes
	
	printf("%d\n", f);
	
	return 0;
}
