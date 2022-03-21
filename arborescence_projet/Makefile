# Variables internes (compilateur et ses flags)
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
EXEC=hello

# "$@" le nom de la cible
# "$<" le nom de la premiere dependance
# "$^" la liste des dependances
# "$?" la liste des dependances plus recentes que la cible
# "$*" le nom du fichier sans suffixe

#cibles : dependances & regles (a la ligne avec un TAB)
all: $(EXEC)

hello: hello.o main.o
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o : main.c hello.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)