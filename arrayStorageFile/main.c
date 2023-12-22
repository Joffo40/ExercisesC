#include <stdio.h>
#include <stdlib.h>

int main()
{


    char ligne[100];
    int n = 0;
    char stringArray[800][100];



    FILE *fptr;
    fptr = fopen("texte.txt", "r");
//aquisition
    while(fgets(ligne, 100, fptr) != NULL)
    {

        for (int z=0;z<100;z++)
        {
            stringArray[n][z]=ligne[z];

        }
        n++;
    }

//affichage
    for (int i=0;i<n-1;i++)
    {
        for(int y=0;y<100;y++)
        {
            printf("%c",stringArray[i][y]);
        }
        printf("\n");
    }



    return 0;
}
