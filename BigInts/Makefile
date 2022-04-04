# Variables internes (compilateur et ses flags)
CC=gcc
CFLAGS=-Wall
EXEC=unbounded_int_test calc_unbounded_int

# "$@" le nom de la cible
# "$<" le nom de la premiere dependance
# "$^" la liste des dependances
# "$?" la liste des dependances plus recentes que la cible
# "$*" le nom du fichier sans suffixe

#cibles : dependances & regles (a la ligne avec un TAB)
all: $(EXEC)

unbounded_int_test: unbounded_int.o unbounded_int_test.o
	$(CC) -o $@ $^

calc_unbounded_int: unbounded_int.o calc_unbounded_int.o
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)