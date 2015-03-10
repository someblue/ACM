#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 300000;
int cas = 1;

int n;
map<int,int> mp1,mp2;
int ans[N],rec[N];

int find(int x)
{
    if(mp2.count(x)==0) return x;
    if(mp2[x]==0) return 0;
    return mp2[x]=find(mp2[x]);
}

void deal(int p,int v)
{
    while(p<=n)
    {
        ans[p]=v;
        p+=2;
        v=mp1[v];
    }
}

void run()
{
    int x,y;
    mp1.clear(); mp2.clear();
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        mp1[x]=y;
        mp2[y]=x;
        rec[i]=y;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        int p = find(rec[i]);
        if(p==0)
        {
            if(ans[0]==-1) deal(0,0),cnt++;
            if(cnt>=2) break;
        }
        else
        {
            if(ans[1]==-1) deal(1,p),cnt++;
            if(cnt>=2) break;
        }
    }
    printf("%d",ans[1]);
    for(int i=2;i<=n;i++)
        printf(" %d",ans[i]);
    puts("");
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
