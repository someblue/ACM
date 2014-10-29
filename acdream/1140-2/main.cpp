#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define N 5000001
#define REP(i,n) for(i=0;i<(n);++i)
using namespace std;
int cnt[N],n;

inline int readint()
{
    char c;
    int res=0;
    c=getchar();
    while(!isdigit(c))  c=getchar();
    while(isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void run()
{
    int i,a;
    memset(cnt,0,sizeof(int)*(n+1));
    REP(i,n)
    {
        //scanf("%d",&a);
        a=readint();
        cnt[a]++;
    }
    if(n==1)    {cout<<a<<endl;return;}
    int m1,idx;
    int m2;
    m1=0;
    for(i=1;i<N;++i)
        if(m1<cnt[i])
        {
            m1=cnt[i];
            idx=i;
        }
    m2=0;
    for(i=1;i<N;++i)
    {
        if(i==idx)  continue;
        if(m2<cnt[i])   m2=cnt[i];
    }
    int m,tot,l;
    long long ans=0;
    for(i=1;i<N;++i)
    {
        if(!cnt[i]) continue;
        if(i==idx)  m=m2;
        else        m=m1;
        tot=n-cnt[i];
        if(m>=tot-m)    l=m-(tot-m);
        else            l=tot&1;
        if(l<cnt[i])    ans+=i;
    }
    printf("%lld\n",ans);
}

void text()
{
    int a;
    while(1)
    {
        a=readint();
        cout<<a<<endl;
    }
}

int main()
{
    //text();
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
