#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2

int id[128];
void pre()
{
    char c;
    for(c=30;c<127;c++)
        if(c>='A' && c<='Z') id[c]=c-'A';
        else id[c]=c-'a'+30;
}

int n=id['z']+1;
int m;
int first[N];
int d[N];
bool done[N];
int g[N][N];

void dij(int s)
{
    for(int i=0;i<n;i++)
        d[i]=INF;
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(done,0,sizeof(done));
    q.push(make_pair(d[s],s));
    while(!q.empty())
    {
        pii u=q.top(); q.pop();
        int x = u.second;
//        cout<<x<<endl;
        if(x<29 && x!=id['Z'])
        {
            printf("%c %d\n",x+'A',d[x]);
            return;
        }
        if(done[x]) continue;
        done[x]=1;
        for(int v=0;v<n;v++)
        {
            if(g[x][v]==-1 || x==v)  continue;
            if(d[v]>d[x]+g[x][v])
            {
                d[v]=d[x]+g[x][v];
                q.push(make_pair(d[v],v));
            }
        }
    }
}

int cnt;

void run()
{
    char s1[10],s2[10];
    int i,a,b,c;
    cnt=0;
    memset(g,-1,sizeof(g));
    for(i=0;i<m;i++)
    {
        scanf("%s%s%d",s1,s2,&c);
        a=id[s1[0]];
        b=id[s2[0]];
        if(g[a][b]==-1 || g[a][b]>c)
        {
            g[a][b]=g[b][a]=c;
        }
    }
    dij(id['Z']);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    pre();
    n=id['z']+1;
//    cout<<"n="<<n<<endl;
    while(scanf("%d",&m)!=EOF)
        run();
    return 0;
}
