#include <stdio.h>
#include <stdlib.h>

int main()
{


    char ligne[100];
    int n = 0;
    char stringArray[800][100];
    int y = 0;
    int debug=0;

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
    for (int i=0;i<n;i++)
    {
        y=0;
        while(stringArray[i][y] != '\0')
        {
            printf("%c",stringArray[i][y]);
            //scanf("%d", &debug);
            y++;
        }
        //scanf("%d", &debug);
        printf("\n");
    }



    return 0;
}
