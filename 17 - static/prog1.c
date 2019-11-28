struct complex {
	int re;
	int im;
};

struct complex num = { 3, 4 }; // alocação estática

int x = 8;                     // alocação estática

int func() {
	register int a = 1;
	static int b = 1;          // alocação estática (!!!)
	auto int c = 1;            // alocação automática
	int d = 1;                 // alocação automática
	
	return a + b + c + d;
}

int main() {
	return func();
}
