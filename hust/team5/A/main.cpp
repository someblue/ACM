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
typedef pair<int,int> pii;
const ll INF=1LL<<50;
const double eps=1e-6;
const int N = 5010;
int n;
ll v[N],a[N],dp[N];
vector<pii> key;
#define l first
#define r second

void run()
{
    for(int i=1;i<=n;++i)
        scanf("%I64d",&v[i]);
    for(int i=1;i<=n;++i)
        scanf("%I64d",&a[i]);
    a[0]=0;
    int lf,ri,ls,rs;
    key.clear();
    for(ls=rs=0,lf=0,ri=n+1;lf<ri;)
    {
//        if(ls<=rs)
//            ls+=v[++lf];
//        else
//            rs+=v[--ri];
//        if(ls==rs && lf<ri)
//            key.push_back(make_pair(lf,ri));
        if(ls==rs)
        {
            if(lf==ri) break;
            key.push_back(make_pair(lf,ri));
            ls += v[++lf];
            rs += v[--ri];
        }
        else if(ls<rs)
            ls += v[++lf];
        else
            rs += v[--ri];
    }
    if(key.empty())
    {
        printf("%I64d\n",a[n]);
        return;
    }
    int sz = key.size();
    for(int i=0;i<sz;++i)
    {
        dp[i]=a[key[i].l]+a[n-key[i].r+1];
        for(int j=0;j<i;++j)
            dp[i]=min(dp[i],dp[j]+a[key[i].l-key[j].l]+a[key[j].r-key[i].r]);
    }
    ll ans = INF;
    for(int i=0;i<sz;++i)
        ans = min(ans,dp[i]+a[key[i].r-key[i].l-1]);
    printf("%I64d\n",ans);
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF && n)
        run();
    return 0;
}
