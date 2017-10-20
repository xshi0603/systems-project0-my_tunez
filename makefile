all: tunez.o
	gcc -o tunez tunez.o

tunez.o: tunez.c main.c
	gcc -c tunez.c

clean:
	rm *o
	rm *~

run: all
	./tunez
