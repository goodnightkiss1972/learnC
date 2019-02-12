#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main() {
    FILE *file1, *file2;
    int i, table[5] = {0, 10, 20, 30, 40};
    int table2[5];

    // ecriture vers un fichier en clair
    errno = 0;
    file1 = fopen("source.txt", "w");
    if (file1 == NULL) {
        fprintf(stderr, "Error opneing file 1: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 5; i++) {
        fprintf(file1, "%d\n", table[i]);
    }
    fclose(file1);

    // ecriture vers un fichier binaire
    errno = 0;
    file2 = fopen("source.bin", "wb");
    if (file2 == NULL) {
        fprintf(stderr, "Error opneing file 1: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 5; i++) {
        fwrite(table, sizeof(table[0]), sizeof(table)/sizeof(table[0]), file2);
    }
    fclose(file2);

    // lecture depuis un fichier en clair
    file1 = fopen("source.txt", "r");
    for (i = 0; i < 5; i++){
        fscanf(file1, "%d\n", &table2[i]);
        printf("Recu(%d)= %d\n", i, table[i]);
    }
    fclose(file1);

    // lecture depuis un fichier binaire
    file2 = fopen("source.bin", "rb");
    for (i = 0; i < 5; i++){
        fread(table2, sizeof(table2[0]), sizeof(table2[0])/sizeof(table2), file2);
        printf("Recu bin(%d)= %d\n", i, table[i]);
    }
    fclose(file2);


    return 0;

}