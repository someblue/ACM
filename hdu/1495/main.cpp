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
#define N 105
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

bool vis[N][N];
int cap[3];

struct _node{
    int w[3],dep;
    _node(const _node k,int a,int b)
    {
        for(int i=0;i<3;i++)    w[i]=k.w[i];
        int m=min(w[a],cap[b]-w[b]);
        w[a]-=m;
        w[b]+=m;
        dep = k.dep+1;
    }
    _node()
    {
        w[0]=cap[0];
        w[1]=w[2]=0;
        dep=0;
    }
};

bool ok(_node k,int a,int b)
{
    return k.w[a]>0 && cap[b]>k.w[b];
}

bool find_tag(_node k)
{
    int cnt=0,i,rec=-1,idx;
    for(i=0;i<3;i++)
        if(k.w[i]==0)
            cnt++,idx=i;
    if(cnt!=1)  return 0;
    for(i=0;i<3;i++)
    {
        if(i==idx)  continue;
        if(rec==-1) rec=k.w[i];
        else    return rec==k.w[i];
    }
    return 0;
}

int bfs()
{
    memset(vis,0,sizeof(vis));
    _node t;
    queue<_node> q;
    int i,j;
    q.push(t);
    while(!q.empty())
    {
        t = q.front();  q.pop();
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(i==j)    continue;
            if(!ok(t,i,j))  continue;
            _node n(t,i,j);
            if(find_tag(n))   return n.dep;
            if(vis[n.w[1]][n.w[2]])    continue;
            vis[n.w[1]][n.w[2]]=1;
            q.push(n);
        }
    }
    return 0;
}

int main()
{
    while(cin>>cap[0]>>cap[1]>>cap[2] && cap[0])
    {
        int k=bfs();
        if(k)   cout<<k<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
