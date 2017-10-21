all: tunez.o
	gcc tunez.o -o tunez.out

tunez.o: tunez.c tunez.h
	gcc -c tunez.c

clean:
	rm -f *o
	rm -f *~

run: all
	./tunez.out
