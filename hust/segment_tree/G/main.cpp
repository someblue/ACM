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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 100010;
int col[N<<2],sum[N<<2];
inline void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
inline void pushdown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
//        sum[rt<<1] = col[rt] * (m-(m>>1));
//        sum[rt<<1|1] = col[rt] * (m>>1);
        col[rt] = 0;
    }
}
void update(int L,int R,int v,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        col[rt] = v;
        sum[rt] = v*(r-l+1);
        return;
    }
    int mid = (l+r)>>1;
    pushdown(rt,l-r+1);
    if(L<=mid)  update(L,R,v,lson);
    if(R>mid) update(L,R,v,rson);
    pushup(rt);
}
void build(int l,int r,int rt)
{
    col[rt] = 0;
    sum[rt] = 1;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int n;
void run()
{
    scanf("%d",&n);
    build(1,n,1);
    cout<<sum[1]<<endl;
    int q,a,b,c; scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        update(a,b,c,1,n,1);
        cout<<sum[1]<<endl;
    }
    static int cas = 1;
    printf("Case %d: The total value of the hook is %d.\n",cas++,sum[1]);
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
