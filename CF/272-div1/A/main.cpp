#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const ll mod = 1000000007;
const double eps = 1e-6;
int cas = 1;

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    ll a,b,tmp,ans;
    while(cin>>a>>b)
    {
        tmp = a*(a+1)/2 % mod;
        tmp *= b;
        tmp += a;
        tmp %= mod;
        ans = b*(b-1)/2 %mod;
        ans *= tmp;
        ans %= mod;
        cout<<ans<<endl;
    }
    return 0;
}
