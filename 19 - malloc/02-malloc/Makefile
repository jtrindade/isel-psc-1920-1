CC=gcc
COPTS=-Wall -pedantic -g -c

all: prog test_xlist

prog: prog.o xmalloc.o xlist.o
	$(CC) -g -o prog prog.o xmalloc.o xlist.o

prog.o: prog.c xmalloc.h
	$(CC) $(COPTS) prog.c

xmalloc.o: xmalloc.c xmalloc.h
	$(CC) $(COPTS) xmalloc.c

xlist.o: xlist.c xlist.h
	$(CC) $(COPTS) xlist.c

test_xlist: test_xlist.o xlist.o
	$(CC) -g -o test_xlist test_xlist.o xlist.o

test_xlist.o: test_xlist.c xlist.h
	$(CC) $(COPTS) test_xlist.c
	
clean:
	rm -f prog test_xlist *.o
