#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 50010;

struct _edge{
    int to,next;
};
_edge edge[N*2];
int ecnt,head[N];
void addedge(int u,int v)
{
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}
struct node{
    int id,a,b,l,r;
    friend bool operator < (const node &a, const node &b)
    {
        return a.a>b.a;
    }
};

int n,m,M;
int zkw[N*10][2];
node man[N];
int ans[N];
int dfscnt;
void dfs(int u,int fa)
{
    man[u].l = dfscnt++;
    for(int e=head[u];e!=-1;e=edge[e].next)
    {
        int &v = edge[e].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    man[u].r = dfscnt++;
}

void add(int x,int a,int b)
{
    for(x+=M;x;x>>=1)
        if(zkw[x][0]<a)
            zkw[x][0]=a,zkw[x][1]=b;
}
int query(int l,int r)
{
    int a,b;
    a=b=-1;
    for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1)
    {
        if(~l&1 && zkw[l^1][0]>a) a=zkw[l^1][0],b=zkw[l^1][1];
        if(r&1 && zkw[r^1][0]>a) a=zkw[r^1][0],b=zkw[r^1][1];
    }
    return b;
}

void run()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    ecnt=0;
    int a,b,c;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,i);
        addedge(i,a);
        man[i].a=c;
        man[i].b=b;
        man[i].id=i;
    }
    dfscnt=1;
    dfs(0,-1);
//    for(int i=0;i<n;i++)
//        printf("%d %d %d\n",i,man[i].l,man[i].r);
    sort(man+1,man+n);

    for(M=1;M<=dfscnt+1;M*=2);
    memset(zkw,-1,sizeof(zkw));

    stack<int> stk;
    stk.push(1);
    ans[man[1].id]=-1;
    for(int i=2;i<n;i++)
    {
        if(man[i].a!=man[i-1].a)
        {
            while(!stk.empty())
            {
                int u = stk.top(); stk.pop();
                add(man[u].l,man[u].b,man[u].id);
                add(man[u].r,man[u].b,man[u].id);
            }
        }
        stk.push(i);
        ans[man[i].id] = query(man[i].l,man[i].r);
    }
    while(m--)
    {
        scanf("%d",&a);
        printf("%d\n",ans[a]);
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
