#include <stdio.h>
#include <stdlib.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

void extremaAbscissNeg(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr);
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr,int tableExtremaPos[],int* dimTableExtremaPosptr);
void extremaAbscissPos(int table[],int dimTable,int tableExtremaPos[],int* dimTableExtremaPosptr);

int main()
{
    int table[]={0,1,3,0,5,2,1,8,2,0};
    int dimTable=sizeof(table)/sizeof(table[0]);
int variable =0;
    int tableExtremaNeg[50];
    int dimTableExtremaNeg=sizeof(tableExtremaNeg)/sizeof(tableExtremaNeg[0]);
    int* dimTableExtremaNegptr = &dimTableExtremaNeg;

    int tableExtremaPos[50];
    int dimTableExtremaPos=sizeof(tableExtremaPos)/sizeof(tableExtremaNeg[0]);
    int* dimTableExtremaPosptr = &dimTableExtremaPos;



    int volumeMax= 0;

    extremaAbscissNeg(table,dimTable,tableExtremaNeg, dimTableExtremaNegptr);
    extremaAbscissPos(table,dimTable,tableExtremaPos, dimTableExtremaPosptr);


//scanf("%d", &variable);
    volumeMax=calculateBiggestVolumLake(table,dimTable,tableExtremaNeg, dimTableExtremaNegptr,tableExtremaPos, dimTableExtremaPosptr);

//printf("%d", volumeMax);
    printf("Le volume maximum est egal à %d.\n",volumeMax);
    //scanf("%d", &variable);
    return 0;
}

void extremaAbscissNeg(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr)
{
    int n =0;
    int firstLevel=0;
    int lastLevel=0;
    int increment =0;
    int j =0;
    int variable=0;

    for(int i=0;i<dimTable;i++)
    {

        if(table[i]>firstLevel)     //Determination du niveau des bornes laterales
        {
            firstLevel=table[i];
            lastLevel=table[i];


        }


    }

    table[0]=firstLevel;
    table[dimTable-1]=lastLevel;

    //tableExtrema[0]=0;


    //printf("%d",dimTable);
    for(j=1;j<dimTable-1;j++) //determination des minimas

    {
//scanf("%d", &variable);
        //printf("%d ", j);
        int boolCondition = ((table[j-1])>(table[j])) && ((table[j])<(table[j+1]));
        if (boolCondition)
        {

            //printf("%d %d %d\ %d \n", boolCondition, table[j],  increment, j);
            //scanf("%d", &variable);

            tableExtremaNeg[increment]= j;
            //scanf("%d",&variable);
            //printf("%d \n", tableExtremaNeg[increment]);
            increment++;

        }

    }

    *dimTableExtremaNegptr=increment;
//scanf("%d", &variable);
//
//




}
void extremaAbscissPos(int table[],int dimTable,int tableExtremaPos[],int* dimTableExtremaPosptr)
{
    int n =0;
    int firstLevel=0;
    int lastLevel=0;
    int increment =0;
    int j =0;
    int variable=0;

    for(int i=0;i<dimTable;i++)
    {

        if(table[i]>firstLevel)     //Determination du niveau des bornes laterales
        {
            firstLevel=table[i];
            lastLevel=table[i];


        }


    }

    table[0]=firstLevel;
    table[dimTable-1]=lastLevel;

    tableExtremaPos[0]=0;
    tableExtremaPos[dimTable-1]=dimTable-1;

    //printf("%d",dimTable);



    for(j=1;j<dimTable-1;j++) //determination des MAXIMUMS

    {
        //printf("%d ", j);
        int boolCondition = ((table[j-1])<(table[j])) && ((table[j])>(table[j+1]));
        if (boolCondition)
        {

            //printf("%d %d %d\ %d \n", boolCondition, table[j],  increment, j);
            //scanf("%d", &variable);

            tableExtremaPos[increment]= j;

            //printf("%d \n", tableExtremaPos[increment]);
            increment++;

        }

    }

    *dimTableExtremaPosptr=increment;
//scanf("%d", &variable);
//
//




}
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtremaNeg[],int* dimTableExtremaNegptr,int tableExtremaPos[],int* dimTableExtremaPosptr)
{
    int volumeMax = 0;
    int volume = 0;
    int const cst =1;
    int variable =0;
    int increment =0;
    int incrementRight=0;
    int incrementLeft=0;
    //printf("%d\n",*dimTableExtremaNegptr);
    for(int i=0;i<*dimTableExtremaNegptr;i++)
    {
        printf("%d ",tableExtremaNeg[i]);

        incrementRight=0;
        incrementLeft=0;


        while((table[tableExtremaNeg[i-incrementRight]-1]>table[tableExtremaNeg[i-incrementRight]]) && (table[tableExtremaNeg[i+incrementLeft]+1]>table[tableExtremaNeg[i+incrementLeft]]))
        {
            if((table[tableExtremaNeg[i-incrementRight]-1])>(table[tableExtremaNeg[i+incrementLeft]+1]))
            {
                printf("%d\n",table[tableExtremaNeg[i+incrementLeft]]);
                volume = volume + (table[tableExtremaNeg[i+incrementLeft]+1]-table[tableExtremaNeg[i+incrementLeft]])* cst;
                incrementLeft++;
            }
            else
            {
                printf("%d\n",table[tableExtremaNeg[i-incrementRight]]);
                volume = volume + (table[tableExtremaNeg[i-incrementRight]-1]-table[tableExtremaNeg[i-incrementRight]]) * cst;
                incrementRight++;
            }


        }
        if(volume>volumeMax)
        {
            volumeMax = volume;

        }

    }
    return volumeMax;

}
