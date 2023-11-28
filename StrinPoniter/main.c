#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OF_ELEMENTS 100
int main()
{
    char texte[NUMBER_OF_ELEMENTS];
    int sizeVariableTexteFinal = 0;
    int sizePointerTexteFinal = 0;

    printf("Entrez une chaine de charactères\n");
    scanf("%s",texte);


    int longReal =strlen(texte);

    char* pointText = calloc(longReal, sizeof(char));


    if (pointText == NULL) /* Memory allocation fails */
	{
		printf("Couldn't allocate memory");
	}
	else  /* Memory allocation successful */
	{
		printf("Memory allocation successful\n");

		/* Generate and store random numbers */
		for (int i = 0; i < longReal; i++)
		{
			pointText[i] = texte[i];
			texte[i] =NULL;
		}
    }
    sizeVariableTexteFinal = sizeof(texte);
    sizePointerTexteFinal = longReal * sizeof(char);

    printf("La dimension du Texte est:%d\n", sizeVariableTexteFinal);
    printf("La dimension du Texte pointé est:%d\n", sizePointerTexteFinal);
    free(pointText);


    return 0;
}
