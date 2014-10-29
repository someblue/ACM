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
const int N = 300010;

ll a[N];
ll n;

void run()
{
    for(int i=1;i<=n;i++)   scanf("%I64d",a+i);
    if(n==1)
    {
        printf("%I64d\n",a[1]);
        return;
    }
//    if(n==2)
//    {
//        printf("%I64d\n",a[1]+a[2]);
//        return;
//    }
    sort(a+1,a+1+n);
    ll ans = 0;
    for(ll i=1;i<n;i++)
        ans += (i+1)*a[i];
    ans += n*a[n];
    printf("%I64d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%I64d",&n)!=EOF)
        run();
    return 0;
}
