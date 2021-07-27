#include<stdio.h>
int main()
{
    int time[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int xb[16] = {100,110,120,129,140,149,158,168,179,188,198,209,219,226,234,240};
    int yb[16] = {0,3,6,10,15,20,26,32,37,34,30,27,23,19,16,14};

    float xf[16],yf[16];
    printf("Enter Fighter's Initial Position(x,y) : ");
    scanf("%f %f" , &xf[0],&yf[0]);
    int S;
    printf("\n\nEnter the Fighter speed: ");
    scanf("%d",&S);

    float sin[16],cos[16],dist[16];

for(int i = 0;i<16;i++)
{
    dist[i] = sqrt(pow((yb[i]-yf[i]),2)+pow((xb[i]-xf[i]),2));
    sin[i] = (yb[i]-yf[i])/dist[i];
    sin[i] = (xb[i]-xf[i])/dist[i];
    xf[i+1]= xf[i]+ S*cos[i];
    yf[i+1]= yf[i]+ S*sin[i];
}

printf("\n\nyb[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",yb[i]);
}
printf("]\n\n");

printf("\n\nyf[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",yf[i]);
}
printf("]\n\n");

printf("\n\nxb[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",xb[i]);
}
printf("]\n\n");

printf("\n\nxf[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",xf[i]);
}
printf("]\n\n");

printf("\n\ndist[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",dist[i]);
}
printf("]\n\n");

printf("\n\nsin[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",sin[i]);
}
printf("]\n\n");

printf("\n\ncos[t] : [");
for(i=0;i<16;i++)
{
    printf(" %d ",cos[i]);
}
printf("]\n\n");

    return 0;
}
