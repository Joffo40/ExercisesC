#include <stdio.h>
#include <stdlib.h>

int main()
{
    char charactere='i';
    char *table1 = malloc(sizeof(char) * 1);
    char *table2 = malloc(sizeof(char) * 1);
    FILE *fptr1;
    FILE *fptr2;
    FILE *fptrFinal;
    int nbrCharTexte1=0;
    int nbrCharTexte2=0;


    fptr1 = fopen("texte1.txt", "r");
    fptr2 = fopen("texte2.txt", "r");
    fptrFinal = fopen("final.txt", "w");


    // Lecture du fichier texte1.txt
    while(charactere != EOF )
    {
        charactere=getc(fptr1);
        nbrCharTexte1++;
        char *table1 = malloc(sizeof(char) * nbrCharTexte1);
        table1[nbrCharTexte1-1]=charactere;
        printf("%c",table1[nbrCharTexte1-1]);

    }

    charactere='i';

        // Lecture du fichier texte2.txt
    while(charactere != EOF )
    {
        charactere=getc(fptr2);
        nbrCharTexte2++;
        char *table2 = malloc(sizeof(char) * nbrCharTexte2);
        table2[nbrCharTexte2-1]=charactere;
        printf("%c",table2[nbrCharTexte2-1]);

    }
    //ecriture des charactères du fichier texte1
    for (int i = 0 ; i < nbrCharTexte1 ; i = i + 1)
    {
        printf("%c",table1[i]);
        fputc(table1[i],fptrFinal);

    }

    //ecriture des charactères du fichier texte2
    for (int j = 0 ; j < nbrCharTexte2 ; j = j + 1)
    {
        printf("%c",table1[j]);
        fputc(table1[j],fptrFinal);

    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptrFinal);




}
