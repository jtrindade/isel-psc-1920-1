int funcA();  // from prog3a.c
int funcBx();  // from prog3b.c
int funcBy();  // from prog3b.c

int main() {
	int a1 = funcA();  // 100
	int b1 = funcBx(); // 10000
	int a2 = funcA();  // 101
	int a3 = funcA();  // 102
	int b2 = funcBy(); // 10001
	int a4 = funcA();  // 103
	int b3 = funcBx(); // 10000

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a1, b1, a2, a3, b2, a4, b3);
	
	return a1 + a2 + a3 + a4 + b1 + b2 + b3;
}
