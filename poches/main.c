#include <stdio.h>
#include <stdlib.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

void extremaAbscissNeg(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr);
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr,int tableExtremaPos[],int* dimTableExtremaPosptr);
void extremaAbscissPos(int table[],int dimTable,int tableExtremaPos[],int* dimTableExtremaPosptr);
void nouveauTableaux(int table[],int dimTable, int usedTable[], int dimUsedTable);

int main()
{
    int table[]={1,3,0,5,2,1,8,2};
    int dimTable=sizeof(table)/sizeof(table[0]);


    int usedTable[10];



    int dimUsedTable=sizeof(usedTable)/sizeof(usedTable[0]);
    nouveauTableaux(table,dimTable,usedTable,dimUsedTable);  //fonction qui donne des extremités au tableau en creant un nouveau tableau avec 0 en valeuer

    int tableExtremaNeg[50];
    int dimTableExtremaNeg=sizeof(tableExtremaNeg)/sizeof(tableExtremaNeg[0]);
    int* dimTableExtremaNegptr = &dimTableExtremaNeg;

    int tableExtremaPos[50];
    int dimTableExtremaPos=sizeof(tableExtremaPos)/sizeof(tableExtremaNeg[0]);
    int* dimTableExtremaPosptr = &dimTableExtremaPos;



    int volumeMax= 0;

    //extremaAbscissNeg(usedTable,dimUsedTable,tableExtremaNeg, dimTableExtremaNegptr);  //fonction donnant les extrémas minimums ---inutile----
    extremaAbscissPos(usedTable,dimUsedTable,tableExtremaPos, dimTableExtremaPosptr);       //fonction donnant les extrémas maximums



    volumeMax=calculateBiggestVolumLake(usedTable,dimUsedTable,tableExtremaNeg, dimTableExtremaNegptr,tableExtremaPos, dimTableExtremaPosptr);   // fonction calculant le volume max des lacs


    printf("Le volume maximum est egal à %d.\n",volumeMax);  //affichage du volume max

    return 0;
}

void extremaAbscissPos(int table[],int dimTable,int tableExtremaPos[],int* dimTableExtremaPosptr)
{
    int n =0;
    int firstLevel=0;
    int lastLevel=0;
    int increment =0;
    int j =0;
    int variable=0;





    for(int i=1;i<dimTable-1;i++)
    {

        if(table[i]>firstLevel)     //Determination du niveau des bornes laterales -- maximums de toutes les valeurs
        {
            firstLevel=table[i];
            lastLevel=table[i];


        }


    }
    table[0]=firstLevel; //affectation de la valeur maximale aux extrémités du tableau
    table[dimTable-1]=lastLevel;


    tableExtremaPos[0]=0;



    for(j=1;j<dimTable-1;j++) //determination des extremas MAXIMUMS

    {

        int boolCondition = ((table[j-1])<(table[j])) && ((table[j])>(table[j+1]));
        if (boolCondition)
        {



            tableExtremaPos[increment]= j;


            increment++;

        }

    }
    tableExtremaPos[dimTable-1]=dimTable-1;

    *dimTableExtremaPosptr=increment+1;   //nouvelle dimension du tableau apres determination des extremats





}
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr,int tableExtremaPos[],int* dimTableExtremaPosptr)
{
    int volumeMax = 0;
    int volume = 0;
    int const cst =1;

    int j=0;

    for(int i =  0; i<*dimTableExtremaPosptr-1; i++)  // passage en revue des n-1 extremats positifs
    {
        int j=1;

        if((table[tableExtremaPos[i]])<=(table[tableExtremaPos[i+1]]))    //determination du niveau maximum du lac
        {
            while((table[tableExtremaPos[i]+j])< (table[tableExtremaPos[i]]))   //pas à pas, on verifie que une colonne d'eau peut etre acumulée
            {

                volume = volume + cst * (table[tableExtremaPos[i]]-table[tableExtremaPos[i]+j]);    //calcul de la colonne d'eau et ajout au volume d'eau deja calculé
                j++;
            }

        }
        else
        {
            while((table[tableExtremaPos[i]+j])< (table[tableExtremaPos[i+1]]))  //pas à pas, on verifie que une colonne d'eau peut etre acumulée
            {

                volume =volume + cst * (table[tableExtremaPos[i+1]]-table[tableExtremaPos[i]+j]);       //calcul de la colonne d'eau et ajout au volume d'eau deja calculé
                j++;
            }


        }




        if(volume>volumeMax)    //Determination du volume du lac maximum
        {
            volumeMax = volume;

        }
        volume=0;
    }
    return volumeMax;

}
void nouveauTableaux(int table[],int dimTable, int usedTable[], int dimUsedTable)  //fonction qui donne des extremités au tableau en creant un nouveau tableau avec 0 en valeuer
{

    usedTable[0]=0;

    for(int i=0;i<dimTable; i++)
    {
        usedTable[i+1]=table[i];

    }

    usedTable[dimUsedTable-1]=0;







}

