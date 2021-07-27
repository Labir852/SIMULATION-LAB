#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float RandomNum(int lo, int up)
{
        float num = ((float)rand()/RAND_MAX)*(float)(up);
        return num;
}


int main()
{
    float diameter;

    printf("Enter the Diameter: ");
    scanf("%f",&diameter);


    float radius = diameter/2;
    int m=0,range,n=1;


    printf("\nEnter How many step should be printed: ");
    scanf("%d",&range);

    float R1[range],R2[range],checkValue[range];
    for (int i=0;i<range;i++)
    {
            R1[i]=RandomNum(0,radius);
            R2[i]=RandomNum(0,radius);
    }

    int mValues[range],nValues[range];
    mValues[0]=0,nValues[0]=1;

    float value;
    for(int i=0;i<range;i++)
    {
        value = (radius*radius) -(R1[i]*R1[i]);
        checkValue[i]= sqrt(value);
        if(R2[i]<= checkValue[i])
        {
            m+=1;
        }
        n+=1;
        mValues[i+1]=m,nValues[i+1]=n;
    }

    printf("\nR1: [");
    for(int i=0;i<range;i++)
    {
        printf(" %f ",R1[i]);
    }
    printf("]\n");

    printf("\nR2: [");
    for(int i=0;i<range;i++)
    {
        printf(" %f ",R2[i]);
    }
    printf("]\n");

    printf("\nsqrt(1-R1^2): [");
    for(int i=0;i<range;i++)
    {
        printf(" %f ",checkValue[i]);
    }
    printf("]\n");


    printf("\nM : [");
    for(int i=0;i<range;i++)
    {
        printf(" %d ",mValues[i]);
    }
    printf("]\n");


    printf("\nN: [");
    for(int i=0;i<range;i++)
    {
        printf(" %d ",nValues[i]);
    }
    printf("]\n");



float piValue = (m-1)*4/(n-1);

    printf("\n\n The value of pi is: %f \n\n", piValue);







    return 0;
}
