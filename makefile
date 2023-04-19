all: cesar

cesar: cesar.c cesar.h
	gcc cesar.c -o cesar

clean:
	rm -f cesar cesar.o

