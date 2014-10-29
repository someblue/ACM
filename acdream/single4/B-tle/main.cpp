#include <bits/stdc++.h>
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,n) for(i=1;i<=(n);++i)
#define N 1000005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
const int INF = 1<<30;
const double eps = 0.000001;

int prm[N];
ll a[N],sum[N];

void make_prm()
{
    int i,j;
    for(i=2;i<N;i++)
    {
        if(prm[i]) continue;
        for(j=i*2;j<N;j+=i)
            prm[j]=i;
    }
}

ll pow_mod(ll a,ll n,ll m)
{
    if(!n) return 1;
    ll x=pow_mod(a,n/2,m);
    ll ans=x*x%m;
    if(n%2==1) ans = ans*a%m;
    return ans;
}

void run()
{
    ll n,m,p;
    int i;
    scanf("%lld%lld%lld",&n,&m,&p);

    a[0]=0;a[1]=1;
    sum[0]=0;
    for(i=2;i<p;i++)
    {
        if(prm[i])
        {
            a[i]=a[prm[i]]*a[i/prm[i]];
            while(a[i]>=p) a[i]-=p;
//            a[i]=a[prm[i]]*a[i/prm[i]]%p;
        }
        else
            a[i]=pow_mod(i,m,p);
    }
    for(i=1;i<p;i++)
    {
        sum[i]=sum[i-1]+a[i];
        if(sum[i]>=p) sum[i]-=p;
    }
    ll ans=sum[p-1]*(n/p)%p + sum[n%p];
    ans%=p;
    printf("%lld\n",ans);
}

int main()
{
    make_prm();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
