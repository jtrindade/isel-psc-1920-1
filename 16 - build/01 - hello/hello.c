#define MESSAGE "Hello, world!"
#define OK 0
#define principal main
#define GOOD OK

int puts(const char * str);

int principal() {
	puts(MESSAGE);
	return GOOD;
}
