#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 15;
int cas = 1;

vector<int> ans;
vector<pii> bomb;
int g[N][N], tmp[N][N];
int n,m,k;

bool judge()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(g[i][j]!=-1 && g[i][j]!=tmp[i][j])
                return 0;
    return 1;
}

void run()
{
    ans.clear();
    bomb.clear();
    k = 0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]==-1)
            {
                k++;
                bomb.push_back(make_pair(i,j));
            }
        }
    cout << "k = " << k << endl;
    for(int s=0; s<(1<<k); s++)
    {
        memset(tmp,0,sizeof(tmp));
        for(int i=0; i<k; i++)
        {
            if(s&(1<<i))
                for(int x=bomb[i].first-1; x<=bomb[i].first+1; x++)
                    for(int y=bomb[i].second-1; y<=bomb[i].second+1; y++)
                        tmp[x][y]++;
        }
        if(judge())
        {
            ans.push_back(s);
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(g[i][j]==-1)
                    {
                        cout << "x ";
                    }
                    else cout << tmp[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }
    int a,b,sa,sb;
    sa = sb = ans[0];
    for(unsigned int i=1; i<ans.size(); i++)
        sa &= ans[i], sb |= ans[i];
    a = b = 0;

    for(unsigned int i=0; i<ans.size(); i++)
    {
        for(int i=0; i<k; i++)
            if(ans[i]&(1<<i)) cout << "1 ";
            else cout << "0 ";
        cout << endl;
    }

    for(int i=0; i<k; i++)
    {
        if((sa&(1<<i)) == 1)
            a++;
        if((sb&(1<<i)) == 0)
            b++;
    }
    printf("%d %d\n",a,b);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
