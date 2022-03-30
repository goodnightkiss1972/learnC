# Variables internes (compilateur et ses flags)
CC=gcc
CFLAGS=-Wall -g -pedantic
EXEC=unbounded_int
SRC=unbounded_int.c main.c
OBJ=$(SRC:.c=.o)

# "$@" le nom de la cible
# "$<" le nom de la premiere dependance
# "$^" la liste des dependances
# "$?" la liste des dependances plus recentes que la cible
# "$*" le nom du fichier sans suffixe

#cibles : dependances & regles (a la ligne avec un TAB)
all: $(EXEC)

unbounded_int: $(OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)