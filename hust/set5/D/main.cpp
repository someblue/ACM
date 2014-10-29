#include <iostream>
#include <cstdio>
#include <cstring>
#define N 50005
using namespace std;

int n,m;
int dmin[N][20],dmax[N][20],a[N];

void RMQMIN_init(int d[][20])
{
    for(int i=0;i<n;++i)  d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1 <n;++i)
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
void RMQMAX_init(int d[][20])
{
    for(int i=0;i<n;++i)  d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1 <n;++i)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQMIN(int d[][20],int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)    k++;
    return min(d[l][k],d[r-(1<<k)+1][k]);
}
int RMQMAX(int d[][20],int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)    k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

void run()
{
    int i;
    for(i=0;i<n;++i)    scanf("%d",&a[i]);
    RMQMIN_init(dmin);
    RMQMAX_init(dmax);
    int l,r;
    while(m--)
    {
        scanf("%d%d",&l,&r);
        l--;r--;
        printf("%d\n",RMQMAX(dmax,l,r)-RMQMIN(dmin,l,r));
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
