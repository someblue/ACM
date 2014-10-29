#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 505
using namespace std;

bool g[N][N],vis[N];
int in[N];
int topo[N],topo_cnt;
int n,m;

void topo_sort()
{
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;++i)
        if(in[i]==0)    q.push(i);
    while(!q.empty())
    {
        int x=q.top(); q.pop();
        topo[topo_cnt++]=x;
        for(int i=1;i<=n;++i)
        {
            if(g[x][i])
            {
                in[i]--;
                if(in[i]==0)    q.push(i);
            }
        }
    }
}

void run()
{
    memset(g,0,sizeof(g));
    memset(in,0,sizeof(in));
    topo_cnt=0;
    int i,a,b;
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        if(g[a][b]) continue;
        g[a][b]=1;
        ++in[b];
    }
    topo_sort();
    cout<<topo[0];
    for(i=1;i<n;++i)
        cout<<' '<<topo[i];
    cout<<endl;
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
