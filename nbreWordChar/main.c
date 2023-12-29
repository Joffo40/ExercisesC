#include <stdio.h>
#include <stdlib.h>

int main()
{

    int nbreChar = 0;
    int nbreWord = 0;
    int nbrePar = 0;
    int debug=0;
    int charactere=1;
    FILE *fptr;
    fptr = fopen("texte.txt", "r");
//aquisition


    while(charactere != EOF)
    {


        charactere=fgetc(fptr);
        if((charactere==' ') || (charactere=='\n'))
        {
            nbreWord++;
        }
        //if(charactere!=' ')
        //{
            nbreChar++;
        if((charactere=='\n'))
        {
            nbrePar++;
        }
        //}

    }

//afff

    printf("Le nombre de caractère est %d\n",nbreChar);
    printf("Le nombre de mots est %d\n",nbreWord);
    printf("Le nombre de paragraphes est %d\n",nbrePar);
    return 0;
}
