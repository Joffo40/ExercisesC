#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i =0;
    int taille = 0;
    printf("Entrez le nombre d'elements\n");
    scanf("%d",&taille);
    int table[taille-1];

    for (i=0; i<taille;i++)
    {
        printf("Entrez l'elements %d\n",i+1);
        scanf("%d",table+i);
    }

    for (i=0; i<taille;i++)

        printf("Element %d : %d\n", i+1,*(table+i));



    return 0;
}
