#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1;
int cas = 1;

ll a,b;
ll ans;

void run()
{
    ans = 0;
    while(a && b) {
        if(a<b) swap(a,b);
        ans+=a/b;
        a = a%b;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    while(cin>>a>>b)
        run();
    return 0;
}
