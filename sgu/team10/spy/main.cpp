#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,n) for(i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
int cas=1;
const int N = 200010;
// http://acm.hdu.edu.cn/webcontest/contest_show.php?cid=7966
struct _edge{
    int u,v,next;
    bool use,w;
};
struct _node{
    int fa,eid,a,b;
};
char s[20];
int n,ecnt,first[N];
_edge e[N];
_node node[N];
int ans;
vector<int> anslist;

pii dfs(int now,int a,int b)
{
    if(now==1) return make_pair(a,b);
    if(e[node[now].eid].use) return make_pair(a,b);
    pii newp = dfs(node[now].fa,a,b);
    if(newp.first >= newp.second)
    {
        node[now].a = newp.first;
        node[now].b = newp.second;
        return newp;
    }
//    cout<<"bbbbbbbb"<<endl;
    int eid = node[now].eid;
    e[eid].use=1;
    if(!e[eid].w)
    {
//        cout<<"aaaaaaa"<<endl;
        newp.first++;
        newp.second--;
        e[eid].w=1;
        ans++;
        anslist.push_back(eid);
    }
//        cout<<"---"<<now<<' '<<newp.first<<' '<<newp.second<<endl;
    node[now].a = newp.first;
    node[now].b = newp.second;
    return newp;
}

void bfs()
{
    memset(node,0,sizeof(node));
    queue<int> q;
    node[1].a = node[1].b = 0;
    q.push(1);
    while(!q.empty())
    {
        int now = q.front(); q.pop();
//        cout<<now<<' '<<node[now].a<<' '<<node[now].b<<endl;
        int fa = node[now].fa;
        int eid = node[now].eid;
        node[now].a = node[fa].a;
        node[now].b = node[fa].b;
        if(e[eid].w)
            node[now].a++;
        else node[now].b++;
        if(now==1)  node[now].a=node[now].b = 0;
        if(node[now].a < node[now].b)
        {
//            cout<<now<<' '<<node[now].a<<' '<<node[now].b<<endl;
            dfs(now,node[now].a,node[now].b);
//            cout<<now<<' '<<node[now].a<<' '<<node[now].b<<endl;
//            for(int i=1;i<=n;i++) cout<<e[i].use<<' '; cout<<endl;
//            for(int i=1;i<=n;i++) cout<<e[i].w<<' '; cout<<endl;
//            cout<<endl;
        }
        for(int i=first[now];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            node[v].fa = now;
            node[v].eid = i;
            q.push(v);
        }
    }
}

void run()
{
    ecnt=1; ans=0;
    anslist.clear();
    memset(first,-1,sizeof(first));
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%s",&e[ecnt].v,&e[ecnt].u,s);
        e[ecnt].use = 0;
        if(s[0]=='a')
        {
            e[ecnt].w=0; scanf("%s",s);
        }
        else e[ecnt].w=1;
        int u=e[ecnt].u;
        e[ecnt].next=first[u];
        first[u]=ecnt++;
    }
//    for(int i=1;i<ecnt;i++)
//        printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
    bfs();
    printf("%d\n",ans);
    if(!ans) return;
    printf("%d",anslist[0]);
    for(int sz=anslist.size(),i=1;i<sz;i++)
        printf(" %d",anslist[i]);
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
