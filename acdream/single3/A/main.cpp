#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N 100005
#define M 52
using namespace std;
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;

int bit[N][M],a[N];
int n,m;

inline int lowbit(int x)
{
    return x&-x;
}

inline void add(int x,int y)
{
    int i,j;
    for(i=x;i<=n;i+=lowbit(i))
        for(j=y;j<M;j+=lowbit(j))
            ++bit[i][j];
}
inline void sub(int x,int y)
{
    int i,j;
    for(i=x;i<=n;i+=lowbit(i))
        for(j=y;j<M;j+=lowbit(j))
            --bit[i][j];
}
inline ll get(int x,int y)
{
    if(x==0 || y==0) return 0;
    int i,j,res=0;
    for(i=x;i>0;i-=lowbit(i))
        for(j=y;j>0;j-=lowbit(j))
            res+=bit[i][j];
    return res;
}

inline ll getinv(int x,int y)
{
    return get(x-1,51)-get(x-1,y) + get(n,y-1)-get(x,y-1);
}


void run()
{
    int i;
    int l,r;
    ll ans=0;
    memset(bit,0,sizeof(bit));
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        ans+=getinv(i,a[i]);
        add(i,a[i]);
    }
    printf("%lld\n",ans);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        ans-=getinv(l,a[l]);
        sub(l,a[l]);
        sub(r,a[r]);
        ans-=getinv(r,a[r]);
        swap(a[l],a[r]);
        add(l,a[l]);
        ans+=getinv(l,a[l]);
        add(r,a[r]);
        ans+=getinv(r,a[r]);
        printf("%lld\n",ans);
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
