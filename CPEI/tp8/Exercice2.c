#include <stdio.h>

char* rot13(char* dest, int size, char* src);

int main()
{
    char* source = "Bonjour.";
    char* destination = rot13(destination, 8, source);
    printf("\n%s\n", destination);
}

char* rot13(char* dest, int size, char* src)
{
    printf("\nsrc : %s\n", src);
    if (sizeof(src) > size)
    {
        printf("ERREUR: La taille (size=%d) est trop petite.\n", size);
        return NULL;
    }
    int i = 0;
    while (src[i] != '\0')
    {
        printf("%c %c\n", src[i], (src[i] - 'a' + 13 ) % 26 + 'a');
        i++;
    }
    printf("\ndest: %s\n", dest);
    return dest;
}
