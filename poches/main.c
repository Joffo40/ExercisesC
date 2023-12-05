#include <stdio.h>
#include <stdlib.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

void extremaAbsciss(int table[],int dimTable,int tableExtrema[],int* dimTableExtremaptr);
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtrema[],int* dimTableExtremaptr);

int main()
{
    int table[]={0,1,3,0,5,2,1,8,2,0};
    int dimTable=sizeof(table)/sizeof(table[0]);

    int tableExtrema[50];
    int dimTableExtrema=sizeof(tableExtrema)/sizeof(tableExtrema[0]);
    int* dimTableExtremaptr = &dimTableExtrema;



    int volumeMax= 0;

    extremaAbsciss(table,dimTable,tableExtrema, dimTableExtrema);



    volumeMax=calculateBiggestVolumLake(table,dimTable,tableExtrema,dimTableExtremaptr);

    printf("Le volume maximum est egal à %d.\n",volumeMax);

    return 0;
}

void extremaAbsciss(int table[],int dimTable,int tableExtrema[],int* dimTableExtremaptr)
{
    int n =0;
    int firstLevel=0;
    int lastLevel=0;
    int increment =0;
    int j =0;


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

            tableExtrema[increment]= j;

            printf("%d \n", tableExtrema[increment]);
            increment++;

        }

    }

    dimTableExtremaptr=increment;





}
int calculateBiggestVolumLake(int table[],int dimTable,int tableExtrema[],int* dimTableExtremaptr)
{
    int volumeMax = 0;
    int volume = 0;
    int const cst =1;
    int variable =0;
    for(int i=0;i<dimTableExtremaptr;i++)
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
