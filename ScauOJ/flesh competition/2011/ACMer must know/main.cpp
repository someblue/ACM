#include <iostream>
#include <cstdio>
#define MAXN 100000

using namespace std;

int num[MAXN+10],ansL[MAXN+10],ansR[MAXN+10];

int main()
{
    int T,n,i,max,min,cntL,cntR;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        max=num[0];cntL=1;ansL[0]=0;
        for(i=0;i<n;i++)
        {
            if(num[i]>max)
            {

                ansL[cntL++]=i;
                max=num[i];
            }
        }
        min=num[n-1];cntR=1;ansR[0]=n-1;
        for(i=n-1;i>=0;i--)
        {
            if(num[i]<min)
            {
                ansR[cntR++]=i;
                min=num[i];
            }
        }
        //print answer
        printf("%d\n",cntL);
        for(i=0;i<cntL;i++)
            printf("%d ",ansL[i]);
        printf("\n");
        printf("%d\n",cntR);
        for(i=cntR-1;i>=0;i--)
            printf("%d ",ansR[i]);
        printf("\n");
    }
    return 0;
}
