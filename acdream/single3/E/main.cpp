#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcp(ll a,ll b)
{
    while(true)
    {
        if(a==b)    return a;
        a/=10;b/=10;
    }
}
ll fic(ll n)
{
    if(!n) return 0;
    ll a=n%10,b=n/10;
    return a*b+9*(b-1)*b/2+fic(n/10);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",fic(n-1)+lcp(n-1,n));
    return 0;
}
