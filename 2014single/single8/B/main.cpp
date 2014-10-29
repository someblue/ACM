#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

int n,m;
ll w[N][N],sum[N][N],limit;

void pre()
{
    memset(sum,0,sizeof(sum));
    scanf("%d%d%I64d",&n,&m,&limit);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%I64d",&w[i][j]);
            sum[i][j]=sum[i-1][j]+w[i][j];
        }
}

bool judge(int h)
{
    ll s;
    for(int r=1;r+h-1<=n;r++)
    {
        s=0;
        for(int c=1;c<=h;c++)
            s+=sum[r+h-1][c]-sum[r-1][c];
        if(s<=limit) return 1;
        for(int c=1;c+h<=m;c++)
        {
            s-=sum[r+h-1][c]-sum[r-1][c];
            s+=sum[r+h-1][c+h]-sum[r-1][c+h];
            if(s<=limit) return 1;
        }
    }
    return 0;
}

int solve(int l,int r)
{
    int ans = l;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(judge(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans*ans;
}

void run()
{
    pre();
    printf("%d\n",solve(0,min(n,m)));
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
