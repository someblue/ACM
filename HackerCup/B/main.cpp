#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 30;
int cas = 1;

int g[4],a[N][4],n;

bool dfs(int p, int x, int y, int z)
{
    if(x==g[0] && y==g[1] && z==g[2]) return 1;
    if(p>=n) return 0;
    if(dfs(p+1,x,y,z)) return 1;
    x+=a[p][0];
    y+=a[p][1];
    z+=a[p][2];
    if(x>g[0] || y>g[1] || z>g[2]) return 0;
    if(dfs(p+1,x,y,z)) return 1;
    return 0;
}

void run()
{
    cin>>g[0]>>g[1]>>g[2];
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin>>a[i][j];
    printf("Case #%d: %s\n",cas++,dfs(0,0,0,0)?"yes":"no");
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
