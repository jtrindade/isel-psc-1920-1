all: prog libcalc.so

prog: prog.o libcalc.so
	gcc -g -o prog prog.o ./libcalc.so

prog.o: prog.c calc.h
	gcc -Wall -pedantic -g -c prog.c

libcalc.so: calc.o
	gcc -g -shared -o libcalc.so calc.o

calc.o: calc.c calc.h
	gcc -Wall -pedantic -g -fPIC -c calc.c

clean:
	rm -f *.o *.so prog
