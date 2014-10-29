#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define N 110
#define NN 6000
using namespace std;
typedef vector<int> VI;
typedef long long ll;
double x[N],y[N];
int fa[N];
struct _node{
    int u,v;
    double d;
    friend bool operator < (_node a,_node b)
    {
        return a.d<b.d;
    }
};
_node l[NN];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void run()
{
    int _,n;
    int i,j,cnt,u,v;
    double d,ans;
    bool vis;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        cnt=0;ans=0;
        for(i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                if(d>=10&&d<=1000)
                {
                    l[cnt].u = i;
                    l[cnt].v = j;
                    l[cnt].d = d*100;
                    cnt++;
                }
            }
        sort(l,l+cnt);

//        for(i=0;i<cnt;i++) printf("%d,%d,%.1lf\n",l[i].u,l[i].v,l[i].d);

        for(i=0;i<n;i++) fa[i]=i;
        for(i=0;i<cnt;i++)
        {
            u=l[i].u; v=l[i].v;
            u=find(u); v=find(v);
            if(u!=v)
            {
                fa[u] = v;
                ans+=l[i].d;
            }
        }
        for(i=0,vis=0;i<n;i++)
        {
            if(find(i)==i)
            {
                if(!vis) vis=1;
                else
                {
                    vis=0;
                    break;
                }
            }
        }
        if(!vis) printf("oh!\n");
        else printf("%.1lf\n",ans);
    }
}

int main()
{
    freopen("in","r",stdin);
    run();
    return 0;
}
