#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[100];


    FILE *fptr;
    fptr = fopen("texte.txt", "w");

    printf("Veuillez donner le texte à inclure au fichier?");
    scanf("%[^\n]", input);


    fprintf(fptr,input);




    fclose(fptr);





    return 0;
}
