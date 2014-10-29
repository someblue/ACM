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
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 200005;

bool vis[N];
int ans[N];
int a[N];

void run()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    int maxx=-1;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        vis[a[i]]=1;
        if(a[i]>maxx)   maxx=a[i];
    }
    ans[maxx]=maxx+1;
    for(int i=maxx-1;i>=0;--i)
    {
        if(vis[i])
            ans[i]=ans[i+1];
        else
            ans[i]=i;
    }
    int x;
    while(m--)
    {
        scanf("%d",&x);
        if(x>maxx)  printf("%d\n",x);
        else    printf("%d\n",ans[x]);
    }
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
