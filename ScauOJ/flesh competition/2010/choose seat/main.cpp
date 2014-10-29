#include <iostream>
#include <cstdio>
#define N 40

using namespace std;

int main()
{
    int n,q,num[N],i,act,mid;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        if(n<=3)
        {
            num[2]=0;
            num[1]=num[3]=(n==3?1:0);
        }
        else
        {
            mid=n/2+(n&1);
            for(i=1;i<=mid;i++)
                num[i]=num[n+1-i]=n-2-i;
        }
        for(i=0;i<q;i++)
        {
            scanf("%d",&act);
            printf("%d ",num[act]);
        }
        printf("\n");
    }
    return 0;
}
