#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int arr[], int n)
{
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{
    int demand[4], leadTime[3];
    float demandProb[4], leadProb[3];
    int RP1,RP2, days,i;

    printf("\n\nEnter the demand(4 demand values): ");
    for(i=0;i<4;i++)
    {
        scanf("%d",&demand[i]);
    }

    printf("\n\nEnter the Probabilities for demand(4 values): ");
    for(i=0;i<4;i++)
    {
        scanf("%f",&demandProb[i]);
    }

    printf("\n\nEnter the Lead Time(3 Lead time): ");
    for(i=0;i<3;i++)
    {
        scanf("%d",&leadTime[i]);
    }

    printf("\n\nEnter the Probabilities for LeadTime(3 values): ");
    for(i=0;i<3;i++)
    {
        scanf("%f",&leadProb[i]);
    }
    printf("\n\nEnter the value of reorder points respectively: ");
    scanf("%d %d",&RP1,&RP2);

    printf("\n\nHow many days you want to simulate the system: ");
    scanf("%d",&days);

    int demandNums[4],leadNums[3],totalDemands=0,totalLead=0 ;
    int DemandList[days],LeadList[days],j=0,loop=0;

    for(i=0;i<4;i++)
    {
        demandNums[i] = days * demandProb[i];
    }
    for(i=0;i<3;i++)
    {
        leadNums[i] = days * leadProb[i];
    }
    for(i=0;i<4;i++)
    {
        while(loop<demandNums[i])
        {
            DemandList[j] = demand[i];
            j++;
            loop++;
        }
        loop=0;

    }
    j=0;
    for(i=0;i<3;i++)
    {
        while(loop<leadNums[i])
        {
            LeadList[j] = leadTime[i];
            j++;
            loop++;
        }
        loop=0;
    }

    randomize(DemandList,20);
    randomize(LeadList,20);

    int stock[days],Cstock[days],Ord1[days],DDate1[days],ord2[days],DDate2[days],CDemand[days],Shortage[days],CShortage[days];
    printf("Enter the initial Stock: ");
    scanf("%d",&stock[0]);
    Cstock[0] = stock[0];
    CDemand[0] = DemandList[0];
    Shortage[0] = CShortage[0] = 0;



    for(i=0;i<days;i++)
    {
        if (stock[i]>5 && stock[i]<=10)
        {
            Ord1[i] = 15;
            DDate1[i] = LeadList[i]+i;
        }
        else if (stock[i]>0 && stock[i]<=5)
        {
            ord2[i] = 15;
            DDate2[i] = LeadList[i]+i;
        }
        if (stock[i]-DemandList[i]>0 )
        {
            Shortage[i] = 0;
            CShortage[i] = CShortage[i-1]+Shortage[i];
        }





    }














    printf("\n\nDemand: [ ");
    for(i=0;i<days;i++)
    {
        printf(" %d ",DemandList[i]);
    }
    printf(" ]");

    printf("\n\nLead: [ ");
    for(i=0;i<days;i++)
    {
        printf(" %d ",LeadList[i]);
    }
    printf(" ]");



    return 0;
}
