#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

const int MAXN = 1010;
const int MAXM = 4010;
struct Edge{
    int to,next,cap,flow;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;  edge[tol].cap=w;  edge[tol].flow=0;
    edge[tol].next=head[u];  head[u]=tol++;
    edge[tol].to=u;  edge[tol].cap=rw;  edge[tol].flow=0;
    edge[tol].next=head[v];  head[v]=tol++;
}
int Q[MAXN];
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int front=0,rear=0;
    dep[end]=0;
    Q[rear++]=end;
    while(front!=rear)
    {
        int u=Q[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1) continue;
            Q[rear++]=v;
            dep[v]=dep[u]+1;
            gap[dep[v]]++;
        }
    }
}
int S[MAXN];
int sap(int start,int end,int N)
{
    BFS(start,end);
    memcpy(cur,head,sizeof(head));
    int top=0;
    int u=start;
    int ans=0;
    while(dep[start]<N)
    {
        if(u==end)
        {
            int Min = INF;
            int inser;
            for(int i=0;i<top;i++)
                if(Min>edge[S[i]].cap-edge[S[i]].flow)
            {
                Min = edge[S[i]].cap-edge[S[i]].flow;
                inser=i;
            }
            for(int i=0;i<top;i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans+=Min;
            top = inser;
            u=edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u]=i;
                break;
            }
        }
        if(flag)
        {
            S[top++]=cur[u];
            u=v;
            continue;
        }
        int Min = N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap > edge[i].flow && dep[edge[i].to]<Min)
            {
                Min = dep[edge[i].to];
                cur[u]=i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u!=start) u=edge[S[--top]^1].to;
    }
    return ans;
}



void test()
{
    int n,m;
    cin>>n>>m;
    init();
    int u,v,c;
    while(m--)
    {
        cin>>u>>v>>c;
        addedge(u,v,c);
    }
    cout<<sap(1,n,100)<<endl;
}

void run()
{
    int n,m;
    int p,s,e;
    int mn=10000,mx=-1;
    int sp=0, t=1001;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&p,&s,&e);
        if(s<mn) mn=s;
        if(e>mx) mx=e;
        addedge(sp,i,p);
        for(int j=s;j<=e;j++)
            addedge(i,j+500,1);
        //isap.AddEdge(v,u,c);
    }
    for(int i=mn;i<=mx;i++)
        addedge(i+500,t,m);
    cout<<"read"<<endl;
//    for(int i=0;i<isap.edges.size();i+=2)
//        printf("%d %d %d\n",isap.edges[i].from,isap.edges[i].to,isap.edges[i].cap);
    static int cas = 1;
    printf("Case %d: %d\n",cas++,sap(s,t,10));
}

int main()
{
//    test();
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
