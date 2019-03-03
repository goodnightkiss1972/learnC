pour compiler cartesien.h
a priori le tuto piqué sur le net est

compiler cartesien.c
>> gcc -c cartesien.c

ensuite cette etape pour ? pas trop décrite
mais à priori ça permettrait de rassembler plusieurs .o en une seule lib .so
>> gcc -shared cartesien.o -o cartesien.so

finalement il faut écrire son cartesien.h et le mettre dans le répertoire include du compilateur
C:\TDM-GCC-64\include

puis pour compiler ses programmes avec l'inclusion de la librairie :
>> gcc essai.c cartesien.so -o essai
