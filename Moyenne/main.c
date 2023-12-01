#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variable =0;
    int increment = 0;
    int somme =0;
    int moyenne =0;
    int i=0;

    int* table = (int*) malloc(1 * sizeof(int));

    while (1)
    {


        printf("Donnez la valeur %d:(tapez -1 pour sortir)\n", increment+1);
        scanf("%d",&variable);

        if (variable==-1)
        {
            break;
        }
        else
        {

            table[increment]= variable;
        }

        table = (int *) realloc( table, (increment +1) * sizeof(int) );
        increment++;
    }

        //printf("%d\n", increment);  //debugage

    for (i=0; i<increment;i++)

    {
        //printf("%d\n", table[i]);     //debugage
        somme+= table[i];
        //printf("%d\n", somme);        //debugage
        //moyenne /= (increment-1);     //debugage


    }
    moyenne = somme / (i);  // i best incrementé une fois de plus à la fin du bloc...

    free(table);


    printf("La moyenne est egale à: %d", moyenne);


    return 0;
}
