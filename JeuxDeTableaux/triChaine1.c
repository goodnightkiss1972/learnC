#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* affichage du tableau */
static void aff (char const **a, size_t n)
{
   size_t i;
   for (i = 0; i < n; i++)
   {
      printf ("%s\n", a[i]);
   }
   printf ("\n");
}

/* fonction utilisateur de comparaison fournie a qsort() */
static int compare (void const *a, void const *b)
{
   /* definir des pointeurs type's et initialise's
      avec les parametres */
   char const *const *pa = a;
   char const *const *pb = b;

   /* evaluer et retourner l'etat de l'evaluation (tri croissant) */
   return strcmp (*pa, *pb);
}

int main (void)
{
/* tableau a trier (tableau de pointeurs sur char const) */
   char const *tab[] = { "world", "hello", "wild" };

/* affichage du tableau dans l'etat */
   aff (tab, sizeof tab / sizeof *tab);

   qsort (tab, sizeof tab / sizeof *tab, sizeof *tab, compare);

/* affichage du tableau apres le tri */
   aff (tab, sizeof tab / sizeof *tab);

   return 0;
}