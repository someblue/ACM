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
const int N = 65535;
int col[N<<2],vis[N<<1];
inline void pushup(int rt)
{
    if(col[rt<<1] == col[rt<<1|1])
    {
        col[rt] = col[rt<<1];
        col[rt<<1] = col[rt<<1|1] = -1;
    }
}
inline void pushdown(int rt)
{
    if(col[rt]>=0)
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        col[rt]=0;
        return;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int v,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        col[rt] = v;
        return;
    }
    pushdown(rt);
    int mid = (l+r)>>1;
    if(L<=mid) update(L,R,v,lson);
    if(R>mid)  update(L,R,v,rson);
    pushup(rt);
}
void rev(int L,int R,int l,int r,int rt)
{
    int mid = (l+r)>>1;
    if(L<=l && r<=R)
    {
        if(col[rt]>=0)
        {
            col[rt] = !col[rt];
            return;
        }
        rev(L,R,lson);
        rev(L,R,rson);
        pushup(rt);
        return;
    }
    pushdown(rt);
    if(L<=mid) rev(L,R,lson);
    if(R>mid)  rev(L,R,rson);
    pushup(rt);
}
void solve(int l,int r,int rt)
{
    if(l==r)
    {
        vis[l]=col[rt];
        return;
    }
    int mid = (l+r)>>1;
    pushdown(rt);
    solve(lson);
    solve(rson);
}

int main()
{
//    freopen("case.txt","r",stdin);
    char op[5],tc;
    int x,y;
    bool left,right;
    build(0,N,1);
    while(scanf("%s",op)!=EOF)
    {
        scanf("%c%c",&tc,&tc);
        left = (tc=='(');
        scanf("%d",&x);
        scanf("%c",&tc);
        scanf("%d",&y);
        scanf("%c",&tc);
        right = (tc==')');
//        printf("%d %d\n",x,y);
        if(left) x++;
        if(right) y--;
        if(op[0]=='U')
            update(x,y,1,0,N,1);
        else if(op[0]=='I')
        {
            if(x>0) update(0,x-1,0,0,N,1);
            if(y<N) update(y+1,N,0,0,N,1);
        }
        else if(op[0]=='D')
            update(x,y,0,0,N,1);
        else if(op[0]=='C')
        {
            rev(x,y,0,N,1);
            if(x>0) update(0,x-1,0,0,N,1);
            if(y<N) update(y+1,N,0,0,N,1);
        }
        else
            rev(x,y,0,N,1);
    }
    memset(vis,0,sizeof(vis));
    solve(0,N,1);
    for(int i=0;i<=N;++i)
        if(vis[i])
            cout<<i<<' ';
    cout<<endl;
    return 0;
}
