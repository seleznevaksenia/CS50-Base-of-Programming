main: main.o util.o
	gcc -o main main.o util.o
main.o: main.c util.h
	gcc -c -g main.c
util.o: util.c util.h
	gcc -c -g util.c
