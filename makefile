main: build/main.o
	gcc -o bin/main build/main.o
main.o: src/main.c
	gcc -c src/main.c -o build/main.o