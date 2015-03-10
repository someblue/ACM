#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 200010;
int cas = 1;

struct _edge{
    int to,next;
}edge[N];
int ecnt;

int fa[N], head[N], n;
int dp1[N][20],dp2[N][20];
const int top = 20;

void run()
{
    memset(head,-1,sizeof(head));
    ecnt=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",fa+i);
        edge[ecnt].to = i;
        edge[ecnt].next = head[fa[i]];
        head[fa[i]] = ecnt++;
    }
    for(int u=n; u>=1; u--)
    {
        if(head[u]==-1)
        {
            for(int k=1; k<top; k++)
            {
                dp1[u][k] = k;
                dp2[u][k] = k==1?2:1;
            }
        }
        else
        {
            for(int j=1; j<top; j++)
            {
                dp1[u][j] = j;
                for(int e=head[u]; e!=-1; e=edge[e].next)
                {
                    int &v = edge[e].to;
                    dp1[u][j] += dp2[v][j];
                }
            }
            for(int j=1; j<top; j++)
            {
                dp2[u][j] = INF;
                for(int k=1; k<top; k++)
                    if(k!=j && dp1[u][k]<dp2[u][j])
                        dp2[u][j] = dp1[u][k];
            }
        }
    }
//    for(int i=1; i<=n; i++)
//    {
//        cout << i << ": " << endl;
//        for(int j=1; j<=5; j++)
//            cout << dp1[i][j] << ' ';
//        cout << endl;
//        for(int j=1; j<=5; j++)
//            cout << dp2[i][j] << ' ';
//        cout << endl;
//    }
    int ans = INF;
    for(int k=1; k<top; k++)
        if(dp1[1][k] < ans)
            ans = dp1[1][k];
    printf("Case #%d: %d\n",cas++,ans);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
