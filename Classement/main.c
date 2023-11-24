#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimTable=100;
    int tableauNonClasse[dimTable];
    int i=0;
    int j=0;
    int transfert=0;
    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
        srand( time( NULL ) );

    for(i = 0; i < dimTable; i++)
        {
            tableauNonClasse[i] = rand() % 1000 + 1;
            printf("%d   ", tableauNonClasse[i]);

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
            printf("%d   ", tableauNonClasse[i]);

        }



    return 0;
}
