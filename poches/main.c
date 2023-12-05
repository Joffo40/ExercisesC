#include <stdio.h>
#include <stdlib.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

void extremaAbsciss(int table[],int dimTable,int* tableExtrema[]);
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtrema[],int dimTableExtrema);

int main()
{
    int table[10]={0,1,3,0,5,2,1,8,2,0};
    int dimTable=sizeof(table);

    int* tableExtrema[0];
    int volumeMax= 0;

    extremaAbsciss(table,dimTable,tableExtrema);
    printf("%d", sizeof(tableExtrema));

    int dimTableExtrema=sizeof(tableExtrema);
    volumeMax=calculateBiggestVolumLake(table,dimTable,tableExtrema,dimTableExtrema);

    printf("Le volume maximum est egal à %d.\n",volumeMax);

    return 0;
}

void extremaAbsciss(int table[],int dimTable,int* tableExtrema[])
{
    int n =0;
    int firstLevel=0;
    int lastLeevel=0;
    int increment =0;
    int j =0;
    int variable =0;

    for(int i=0;i<dimTable;i++)
    {

        if(table[i]>firstLevel)     //Determination du niveau des bornes laterales
        {
            firstLevel=table[i];
            lastLeevel=table[i];


        }


    }

    table[0]=firstLevel;
    table[dimTable-1]=lastLeevel;

    //tableExtrema[0]=0;



    for(j=1;j<dimTable-1;j++) //determination des minimas

    {
        int boolCondition = ((table[j-1])>=(table[j])) && ((table[j])<=(table[j+1]));
        if (boolCondition)
        {
            increment++;
            //printf("%d %d %d\n", boolCondition, table[j],  increment);
            //scanf("%d", &variable);
            tableExtrema = (int *) realloc( tableExtrema, (increment) * sizeof(int) );
            tableExtrema[increment]= j;
            printf("%d \n", tableExtrema[increment]);

        }

    }

    tableExtrema = (int *) realloc( tableExtrema, (increment+1) * sizeof(int) );
    tableExtrema[increment+1]=dimTable;




}
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtrema[],int dimTableExtrema)
{
    int volumeMax = 0;
    int volume = 0;
    int const cst =1;

    for(int i=0;i<dimTableExtrema;i++)
    {

        int incrementRight =1;
        int incrementLeft =1;

        int boolCondition = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) || ((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));
        int boolCondition2 = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) && ((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));
        int boolCondition3 = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) && !((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));

        while(boolCondition)

            if(boolCondition2)
            {

            volume=+(MIN((table[tableExtrema[i-incrementRight]]),(table[tableExtrema[i+incrementLeft]])) ) * cst;
            incrementRight++;
            incrementLeft++;

            }
            else if(boolCondition3)
            {

            volume=+(MIN((table[tableExtrema[i-incrementRight]]),(table[tableExtrema[i+incrementLeft]])) ) * cst;
            incrementRight++;

            }
            else
            {
            volume=+(MIN((table[tableExtrema[i-incrementRight]]),(table[tableExtrema[i+incrementLeft]])) ) * cst;
            incrementLeft++;

            }
            boolCondition = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) || ((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));
            boolCondition2 = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) && ((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));
            boolCondition3 = (((table[tableExtrema[i]-incrementRight]) >= (table[tableExtrema[i]])) && !((table[tableExtrema[i]+incrementLeft]) >= (table[tableExtrema[i]])));
        }

        if(volume>volumeMax)
        {
        volumeMax=volume;

        }


    return volumeMax;

}
