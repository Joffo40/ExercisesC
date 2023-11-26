#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variableA =0;
    int variableB =0;
    int* ptrA = &variableA;
    int* ptrB = &variableB;
    int somme =0;
    int* ptrSomme = &somme;




    printf("Donnez le premier chiffre\n");
    scanf("%d", ptrA);

    printf("Donnez le deuxieme chiffre\n");
    scanf("%d", ptrB);

    *ptrSomme = *ptrA + *ptrB;
    printf("La somme est egale à %d\n",*ptrSomme);

    return 0;
}
