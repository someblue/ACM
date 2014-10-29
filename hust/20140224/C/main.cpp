#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010

using namespace std;

double sum[N];

int getalice(double mid,int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(sum[i]==mid) return i;
        if(sum[i]>mid)
            return (sum[i]-mid)>(mid-sum[i-1])?i-1:i;
    }
    return -1;
}

int main()
{
    int n,i,alice;
    double t;
    scanf("%d",&n);
    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&t);
        sum[i]=sum[i-1]+t;
    }
    alice=getalice(sum[n]/2,n);
    printf("%d %d\n",alice,n-alice);
    return 0;
}
