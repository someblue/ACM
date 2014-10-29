#include <iostream>
#include <cstdio>
#define N 5000005
using namespace std;

const int INF = 1<<30;
int sum;
int cnt[N];
long long ans;
int maxx[2],idx[2];
int n;

void run()
{
    memset(cnt,0,sizeof(cnt));
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        cnt[j]++;
    }
    maxx[0]=cnt[0];idx[0]=0;
    for(i=1,j=n-2;i<n;i++,j--)
    {
        sum[0][i]=sum[0][i-1]+cnt[i];
        sum[1][j]=sum[1][j+1]+cnt[j];
        if(cnt[i]>maxx[0])
        {
            maxx[0]=cnt[i];
            idx[0]=i;
        }
    }
    maxx[1]=-1;
    for(i=0;i<idx[0];i++)
        if(cnt[i]>maxx[1])
        {
            maxx[1]=cnt[i];
            idx[1]=i;
        }
    for(i=idx[0]+1;i<n;i++)
        if(cnt[i]>maxx[1])
        {
            maxx[1]=cnt[i];
            idx[1]=i;
        }
    ans=0;
    for(i=0;i<n;i++)
    {
        if(i!=idx[0])
        {
            if(maxx[0]>=sum[0][i]+sum[1][i]-maxx[0])    k=maxx[0]-(sum[0][i]+sum[1][i]-maxx[0]);
            else    k=(sum[0][i]+sum[1][i])%2;
            if(cnt[i]>k)    ans+=cnt[i];
        }
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
