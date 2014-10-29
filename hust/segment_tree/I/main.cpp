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
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;
const int N = 10010;

int col[N<<3],n;
bool vis[N];
inline void pushdown(int rt)
{
    if(col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = 0;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        col[rt] = c;
        return;
    }
    pushdown(rt);
    int mid = (l+r)>>1;
    if(L<=mid) update(L,R,c,lson);
    if(R>mid) update(L,R,c,rson);
}
void query(int L,int R,int l,int r,int rt)
{
    int mid = (l+r)>>1;
    if(L<=l && r<=R)
    {
        if(col[rt]) {vis[col[rt]]=1;return;}
        else if(l==r)   return;
        query(L,R,lson);
        query(L,R,rson);
        return;
    }
    pushdown(rt);
    if(L<=mid) query(L,R,lson);
    if(R>mid) query(L,R,rson);
}

vector<int> lisan;
map<int,int> mp;
pii seg[N];

void run()
{
    scanf("%d",&n);
    memset(col,0,sizeof(col));
    lisan.clear(); mp.clear();
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&seg[i].first,&seg[i].second);
        lisan.push_back(seg[i].first);
        lisan.push_back(seg[i].second);
    }
    if(n==1)
    {
        puts("1");
        return;
    }
    sort(lisan.begin(),lisan.end());
    mp[lisan[0]]=1;
    int cnt=2; unsigned int i;
    for(cnt=2,i=1;i<lisan.size();++i)
    {
        if(lisan[i] != lisan[i-1])
            mp[lisan[i]] = cnt++;
    }
    int mx = cnt-1;
    for(int i=1;i<=n;++i)
    {
        update(mp[seg[i].first],mp[seg[i].second],i,1,mx,1);
    }
    memset(vis,0,sizeof(vis));
    query(1,mx,1,mx,1);
    int ans = 0;
    for(int i=1;i<=n;++i)   if(vis[i]) ans++;
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
