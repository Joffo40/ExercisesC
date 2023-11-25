#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimTable=100;
    char tableauNonClasse[dimTable];
    int i=0;
    int j=0;
    char transfert=0;
    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
        srand( time( NULL ) );

    for(i = 0; i < dimTable; i++)
        {
            tableauNonClasse[i] = rand() % 127 + 1;
            printf("%c   ", tableauNonClasse[i]);

        }
    printf("\n\n");

    for (i=0; i< dimTable;i++)
        {
            for (j=i; j<dimTable; j++)
            {
                if (tableauNonClasse[i]>tableauNonClasse[j])
                {
                    transfert= tableauNonClasse[i];
                    tableauNonClasse[i]=tableauNonClasse[j];
                    tableauNonClasse[j]=transfert;

                }

            }
            printf("%c   ", tableauNonClasse[i]);

        }



    return 0;
}
