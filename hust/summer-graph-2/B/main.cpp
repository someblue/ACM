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
#define N 10010
#define cnt(k,x) g[k][x][0]
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

int g[2][N][3],n[2];

void read(int idx)
{
    int m,a,b;
    scanf("%d%d",&n[idx],&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        g[idx][a][++cnt(idx,a)]=b;
        g[idx][b][++cnt(idx,b)]=a;
    }
}

bool judge()
{
    if(n[0]!=n[1])  return 0;
    int i,c;
    for(i=1;i<=n[0];++i)
    {
        if(cnt(0,i)!=cnt(1,i))  return 0;
        c=cnt(0,i);
        if(c==0)    continue;
        if(c==1)    if(g[0][i][1]!=g[1][i][1])  return 0;
        if(c==2)    if(!(min(g[0][i][1],g[0][i][2])==min(g[1][i][1],g[1][i][2]) &&
                          max(g[0][i][1],g[0][i][2])==max(g[1][i][1],g[1][i][2])))  return 0;
    }
    return 1;
}

void run()
{
    static int cas = 1;
    memset(g,0,sizeof(g));
    read(0);
    read(1);
    printf("Case #%d: %s\n",cas++,judge()?"YES":"NO");
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
