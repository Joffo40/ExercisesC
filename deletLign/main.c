#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numLigne=0;
    int lignCount=0;
    int charactere=0;
    int debug=0;
    FILE *fptr;
    FILE *fptr1;
    fptr = fopen("texte.txt", "r");
    fptr1 = fopen("new.txt", "w");
//aquisition
    printf("Entrez la ligne à supprimer :\n");
    scanf("%d", &numLigne);

    while(charactere != EOF )
    {


        charactere=fgetc(fptr);
//scanf("%d", &debug);
        if(lignCount!=numLigne)
        {

            fputc(charactere,fptr1);

        //printf("%c\n",charactere);
        //scanf("%d", &debug);
        }
        else
        {
            fprintf(fptr1,"\n");
            lignCount++;
        }

        if(charactere=='\n')
        {
            lignCount++;
        }
        ;

    }
    fclose(fptr);
    remove(fptr);
    rename("new.txt","texte.txt");
    fclose(fptr1);
    // Close the file

//afff

   return 0;
}
