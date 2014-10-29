#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5000000

typedef long long ll;
using namespace std;

ll n[N+10],cnt[N+10];

void make_table()
{
    memset(n,0,sizeof(n));
    memset(cnt,0,sizeof(cnt));
    int i,j;
    const int N2=N/2;
    for(i=1;i<=N2;i++)
        for(j=i+i;j<=N;j+=i)
            n[j]+=i;
    for(i=1;i<=N;i++)
    {
        if(n[i]>N||n[i]<=i) continue;
        if(n[n[i]]==i) cnt[n[i]]++;
    }
    int p=0;
    for(i=2;i<=N;i++)
    {
        if(cnt[i]) {printf("%d,",(p++,i));
        if(p%10==0) cout<<endl;
        }
        //cnt[i]+=cnt[i-1];
    }
    //cout<<p<<endl;
}


int main()
{
    freopen("case.out","w",stdout);
    make_table();
//    int n;
//    while(~scanf("%d",&n))
//        printf("%I64d\n",cnt[n]);
    return 0;
}
