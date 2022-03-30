#include <stdlib.h>

typedef struct chiffre
{
    struct chiffre *suivant;
    char c;                     /* le chiffre 0-9 */
    struct chiffre *precedent;
} chiffre;

typedef struct
{
    char signe;       /* soit ’+’ soit ’-’ */ /* '*' si invalide */
    size_t len;       /* longueur de la liste */
    chiffre *premier; /* pointeur vers le premier élément de la liste*/
    chiffre *dernier; /*pointeur vers le dernier élément de la liste*/
} unbounded_int;

/* size_t is an unsigned integer type used to represent the size of any object (including arrays) in the particular implementation. The operator sizeof yields a value of the type size_t.
https://en.wikipedia.org/wiki/C_data_types#stddef.h
*/

unbounded_int string2unbounded_int(const char *e);
char *unbounded_int2string(const unbounded_int *unbi);

unbounded_int ajouter_1chiffre_a_la_fin(const char ch, unbounded_int *unbi);
