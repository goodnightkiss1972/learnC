all: hello

hello: hello.o main.o
	gcc -o hello hello.o main.o

hello.o : hello.c
	gcc -o hello.o -c hello.c -W -Wall -ansi -pedantic -std=c99 -g

main.o : main.c hello.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic -std=c99 -g

clean:
	rm -rf *.o

mrproper : clean
	rm -rf hello