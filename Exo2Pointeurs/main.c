#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valueA = 0;
    int valueB = 0;
    int* ptrA = &valueA;
    int* ptrB = &valueB;


    printf("Entrez le premier chiffre\n");
    scanf("%d", ptrA);
    printf("Entrez le deuxieme chiffre\n");
    scanf("%d", ptrB);

    if (*ptrA>*ptrB)
    {
        printf( "%d > %d",*ptrA,*ptrB );

    }
    else
    {
        printf( "%d > %d",*ptrB,*ptrA );

    }


    return 0;
}
