#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int RandomNum(int lo, int up)
{

        int num = (rand() % (up - lo + 1)) + lo;
        return num;
}


int main()
{
    float fProb,lProb,rProb;
    printf("Enter the probabilities for Forward Left & Right respectively : ");
    scanf("%f %f %f",&fProb,&lProb,&rProb);
    int fIDx,lIDx,rIDx,fIDy,lIDy,rIDy;

    char faxis,laxis,raxis;

    printf("Enter for which axis do you want to select for Forward (x // y): ");
    scanf(" %c",&faxis);
    printf("Enter the incrementation/decrementation value for Forward (1 // -1): ");
    if(faxis == 'x')
        scanf("%d",&fIDx);
    else if(faxis == 'y')
        scanf("%d",&fIDy);

    printf("Enter for which axis do you want to select for Left (x // y): ");
    scanf(" %c",&laxis);
    printf("Enter the incrementation/decrementation value for Left (1 // -1): ");
    if(laxis == 'x')
        scanf("%d",&lIDx);
    else if(laxis == 'y')
        scanf("%d",&lIDy);

    printf("Enter for which axis do you want to select for Right (x // y): ");
    scanf(" %c",&raxis);
    printf("Enter the incrementation/decrementation value for Right (1 // -1): ");
    if(raxis == 'x')
        scanf("%d",&rIDx);
    else if(raxis == 'y')
        scanf("%d",&rIDy);


    int x,y,step;
    printf("Enter the starting position for x (0): ");
    scanf("%d",&x);
    printf("Enter the starting position for y (0): ");
    scanf("%d",&y);

    printf("Enter How many simulation step: ");
    scanf("%d",&step);

    int Fn = fProb*10;
    int Rn = rProb*10;
    int Ln = lProb*10;
    int Frand[Fn],Lrand[Ln], Rrand[Rn],stepRand[step];

    for (int i=0;i<Fn;i++)
    {
        Frand[i]=RandomNum(i,Fn);
    }
    for (int i=0;i<Rn;i++)
    {
        Rrand[i]=RandomNum(Fn+1,Fn+Rn);
    }
    for (int i=0;i<Ln;i++)
    {
        Lrand[i]=RandomNum(Fn+Rn+1,Fn+Rn+Ln);
    }

    for (int j =0;j<step;j++)
    {
        stepRand[j] = rand()%10;
        for(int k=0;k<Fn;k++)
        {
            if(stepRand[j] == Frand[k])
            {
                if(faxis == 'x')
                {
                    x += fIDx;
                    break;
                }
                else if(faxis == 'y')
                {
                    y += fIDy;
                    break;
                }
            }
        }
        for(int k=0;k<Rn;k++)
        {
            if(stepRand[j] == Rrand[k])
            {
                if(raxis == 'x')
                {
                    x += rIDx;
                    break;
                }
                else if(raxis == 'y')
                {
                    y += rIDy;
                    break;
                }
            }
        }
        for(int k=0;k<Ln;k++)
        {

            if(stepRand[j] == Lrand[k])
            {
                if(laxis == 'x')
                {
                    x += lIDx;
                    break;
                }
                else if(laxis == 'y')
                {
                    y += lIDy;
                    break;
                }
            }
        }

        printf("\n\nStep: %d \n RandomNumber: %d \n PositionX: %d \n PositionY: %d\n\n",j,stepRand[j],x,y);

        }
        printf("\n\nForward: [");
        for(int n=0;n<Fn;n++)
            printf(" %d ",Frand[n]);
        printf("]");

        printf("\n\nLeft: [");
        for(int n=0;n<Ln;n++)
            printf(" %d ",Lrand[n]);
        printf("]");

        printf("\n\nRight: [");
        for(int n=0;n<Rn;n++)
            printf(" %d ",Rrand[n]);
        printf("]");

        printf("(x,y) = (%d , %d)",x,y);
        return 0;
    }











