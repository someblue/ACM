#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 2010;
const int mod = 1e9+7;
int cas = 1;

int dp1[N][N], dp2[N][N];

void run()
{
    int ma, mb;
    scanf("%d-%d",&ma,&mb);
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[0][0] = 1;
    dp2[0][0] = 1;
    for(int a=0;a<=ma;a++)
        for(int b=0;b<=mb;b++)
    {
        if(a>b && a>=b-1)   dp1[a][b] += dp1[a][b-1];
        if(a>b && a-1>=b)   dp1[a][b] += dp1[a-1][b];
        if(dp1[a][b]>=mod) dp1[a][b]-=mod;
        if(a<=b && a<=b-1)   dp2[a][b] += dp2[a][b-1];
        if(b==mb || (a<=b && a-1<=b)) dp2[a][b] += dp2[a-1][b];
        if(dp2[a][b]>=mod) dp2[a][b]-=mod;
    }
    printf("Case #%d: %d %d\n",cas++,dp1[ma][mb],dp2[ma][mb]);
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
