// Translate with: gcc -Og -c prog.c

// Observe headers with: objdump -x prog.o
// Disassemble with: objdump -d prog.o

// Observe symbol table with: nm -S prog.o

int items[1024*1024];

const int val_x =  8;

int var_a = 1;

const int val_y =  9;

int fun_f(int a, int b) {
	return a + b + val_x;
}

int var_b = 2;
int var_c = 3;

char * fun_g(char * str) {
	return str + 1;
}

const int val_z = 10;

double fun_h(double num) {
	return num + var_c;
}

int main() {
	return 0;
}
