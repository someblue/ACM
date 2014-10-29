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
const int N = 200005;

int mx[N<<2],h,w,n;
void init(int l,int r,int rt)
{
    mx[rt]=w;
    if(l==r)    return;
    int mid = (l+r)>>1;
    init(lson);
    init(rson);
}
inline void pushup(int rt)
{
    mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int v,int l,int r,int rt)
{
    if(l==r)
    {
        mx[rt]-=v;
        return l;
    }
    int mid = (l+r)>>1;
    int res;
    if(mx[rt<<1]>=v)    res = query(v,lson);
    else  res = query(v,rson);
    pushup(rt);
    return res;
}
void run()
{
    int x;
    h = min(h,n);
    init(1,h,1);
    while(n--)
    {
        scanf("%d",&x);
        if(x>mx[1]) puts("-1");
        else printf("%d\n",query(x,1,h,1));
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
        run();
    return 0;
}
