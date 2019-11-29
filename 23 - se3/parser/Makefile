
JSONC_CFLAGS=`pkg-config --cflags json-c`
JSONC_LIBS=`pkg-config --libs json-c`

parser: parser.o
	gcc -g -o parser parser.o ${JSONC_LIBS}

parser.o: parser.c
	gcc -Wall -pedantic -g ${JSONC_CFLAGS} -c parser.c

