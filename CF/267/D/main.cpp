#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2
int n,m;
string e[N];
string s[N*2];
map<string,int> mp;
int cnt;
int sz[N*2],r_num[N*2],fa[N*2];
bool vis[N*2];
struct _edge{
    int to,next;
};
_edge edge[N];
int first[N*2],ecnt;
inline void addedge(int u,int v)
{
    edge[ecnt].to = v;
    edge[ecnt].next = first[u];
    first[u] = ecnt++;
}

inline void deal(string &s)
{
    int sz = s.size();
    for(int i=0;i<sz;i++)
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]-'A'+'a';
}

inline void pre(int i)
{
    sz[i]=s[i].size();
    r_num[i]=0;
    for(int i=0;i<sz[i];i++)
        if(s[i]=='r')
            r_num[i]++;
}

inline bool cmp(int a,int b) // 1 mean: a is better than b
{
    int cnt[a]>cnt[b] || (cnt[a]==cnt[b] && sz[a]<sz[b]);
}

void dfs1(int u,int f)
{
    if(vis[u]) return;
    fa[u]=f;
    for(int e=first[u];e!=-1;e=edge[e].next)
    {
        int &v = edge[e].to;
        if(vis[v]) continue;
        dfs1(v,u);
        if(cmp(best[v],best[u]))
            best[u]=best[v];
    }
}

void dfs2(int u,int b)
{
    if(vis[u]) return;
    best[u]=b;
    for(int e=first[u];e!=-1;e=edge[e].next)
    {
        int &v = edge[e].to;
        if(vis[v]) continue;
        dfs2(v,b);
    }
}

void run()
{
    int i;
    string tmp;
    int u,v;
    for(i=0;i<n;i++)
    {
        cin>>e[i];
        deal(e[i]);
    }
    cnt=0; mp.clear();
    memset(first,-1,sizeof(first));
    ecnt = 0;
    for(i=0;i<m;i++)
    {
        cin>>tmp;
        deal(tmp);
        if(mp.find(tmp)==mp.end())
        {
            s[cnt]=tmp;
            pre(cnt);
            best[cnt]=cnt;
            mp[tmp]=cnt++;
        }
        u=mp[tmp];

        cin>>tmp;
        deal(tmp);
        if(mp.find(tmp)==mp.end())
        {
            s[cnt]=tmp;
            pre(cnt);
            best[cnt]=cnt;
            mp[tmp]=cnt++;
        }
        v=mp[tmp];

        if(u!=v)
            addedge(u,v);
    }
    memset(vis,0,sizeof(vis));
    for(i=0;i<cnt;i++)
        dfs1(i,-1);
    memset(vis,0,sizeof(vis));
    for(i=0;i<cnt;i++)
        if(fa[i]==-1)
            dfs2(i,best[i]);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    while(cin>>n)
        run();
    return 0;
}
