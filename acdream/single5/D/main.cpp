#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;
const ll mod = 1000000007;
const int N = 1000;
ll n;
int num[N][N];

void build()
{
    int i,j,ii,jj;
    int sum=0;
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    {
        num[i][j]=0;
        for(ii=1;ii<=n;++ii)
        for(jj=1;jj<=n;++jj)
        if(fabs(ii-i)<fabs(jj-j))
            num[i][j]++;
        sum+=num[i][j];
    }
    cout<<sum<<endl;
}

ll inv(ll a,ll m)
{
    if(a==1)    return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
ll inv2 = inv(2,mod);
ll inv3 = inv(3,mod);
ll inv6 = inv(6,mod);

void run()
{
    //build();
    if(n==1)    {puts("0");return;}
    ll ans = 0;
//    ans = n*n%mod*(n+1)%mod*(n+1)%mod/2;
//    ans = (ans-5*n*(n+1)%mod*(2*n+1)%mod/6+5*n*(n+1)%mod/2-2*(n-1)-2)%mod;
//    ans = (3*n*n%mod*n%mod*n%mod-10*n*n%mod*n%mod+3*n*n%mod-2*n)/6;
//    ans = n*n%mod*n%mod*n%mod*inv2%mod-2*n%mod*n%mod*n%mod*inv3%mod+n*n%mod*inv2%mod-n*inv3%mod;
//    ans %= mod;
    ans = ((3*n*n%mod*n%mod*n%mod-4*n*n%mod*n%mod+3*n*n%mod)%mod-2*n)%mod;
    ans = (ans*inv6)%mod;
    if(ans<0)   ans+=mod;
    printf("%lld\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
   // cout<<inv2<<' '<<inv3<<endl;
    while(scanf("%lld",&n)!=EOF)
        run();
    return 0;
}
