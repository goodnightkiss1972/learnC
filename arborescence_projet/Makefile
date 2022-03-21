# Variables internes (compilateur et ses flags)
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic

#cibles : dependances & regles
all: hello

hello: hello.o main.o
	$(CC) -o hello hello.o main.o

hello.o : hello.c
	$(CC) -o hello.o -c hello.c $(CFLAGS)

main.o : main.c hello.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper : clean
	rm -rf hello