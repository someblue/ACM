#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;
const int N = 100010;

ll sum[N<<2],addv[N<<2];
inline void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
inline void pushdown(int rt,int m)
{
    if(addv[rt])
    {
        addv[rt<<1] += addv[rt];
        addv[rt<<1|1] += addv[rt];
        sum[rt<<1] += addv[rt] * (m-(m>>1));
        sum[rt<<1|1] += addv[rt] * (m>>1);
        addv[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    addv[rt] = 0;
    if(l==r)
    {
        scanf("%I64d",&sum[rt]);
        return;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,ll v,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
//        addv[rt] += v;
//        sum[rt] += addv[rt] * (r-l+1);
        sum[rt] += v * (r-l+1);
        if(l!=r)    addv[rt] += v;
        return;
    }
    pushdown(rt,r-l+1);
    int mid = (l+r)>>1;
    if(L<=mid)  update(L,R,v,lson);
    if(R>mid) update(L,R,v,rson);
    pushup(rt);
}
ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int mid = (l+r)>>1;
    ll res=0;
    if(L<=mid) res+=query(L,R,lson);
    if(R> mid) res+=query(L,R,rson);
    pushup(rt);
    return res;
}
int n,q;
void run()
{
    build(1,n,1);
    char s[3];
    int a,b;
    ll c;
    while(q--)
    {
        scanf("%s",s);
        scanf("%d%d",&a,&b);
        if(s[0]=='Q')
            printf("%I64d\n",query(a,b,1,n,1));
        else
        {
            scanf("%I64d\n",&c);
            update(a,b,c,1,n,1);
        }
    }
}

int main()
{
//    freopen("case.txt","r",stdin);1
    while(scanf("%d%d",&n,&q)!=EOF)
        run();
    return 0;
}
