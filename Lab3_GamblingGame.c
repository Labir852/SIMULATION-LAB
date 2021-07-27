#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
int RandomNum()
{
    srand(time(NULL));
    int num = (rand() % 10) +1;
    return num;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

int main()
{

        int flipAmount,diff,aftAmnt,games,Chead=0,Ctail = 0,difference = 0,step=0;
    printf("\nEnter Paying Amount for each flip: ");
    scanf("%d",&flipAmount);
    printf("\nEnter difference between heads and tails :");
    scanf("%d",&diff);
    printf("\nEnter Amount of money you get after game: ");
    scanf("%d",&aftAmnt);
    printf("\nHow many games to play: ");
    scanf("%d",&games);
    randomize(arr,10);
    int heads[5],tails[5],allDiff[games],allStep[games];
    for(int i=0;i<5;i++)
    {
            heads[i] = arr[i];

    }
    int j=0;
    for(int i=5;i<10;i++)
    {
        tails[j] = arr[i];
        j++;
    }

    for(int GameNo = 0; GameNo< games; GameNo++)
    {
        while(difference != diff){
                step++;
       int num = RandomNum();
       for(int i=0;i<5;i++)
       {
            if(heads[i] == num)
            {
                Chead +=1;
            }
            else if(tails[i]==num){
                Ctail +=1;
            }
            difference =abs(Chead - Ctail);
       }

       }
       if(difference == diff)
       {
           difference = aftAmnt - step;
           allDiff[GameNo] = difference;
           allStep[GameNo] = step;
           step = 0;
           difference = 0;
       }
    }

    int totalAchieve = games * aftAmnt ,totalPaid=0,grandTotal;
    for(int i=0;i<games;i++)
    {
        totalPaid += (allStep[i]*flipAmount) ;
    }
        grandTotal = totalAchieve - totalPaid;

        if(grandTotal > 0)
        {
            printf("\n\nWin By: %d\n\n",grandTotal );
        }
        else
        {
            printf("\n\nLost By: %d\n\n",grandTotal);
        }

    return 0;
}
