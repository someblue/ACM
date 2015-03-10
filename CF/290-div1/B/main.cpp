#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;

ll gcd(ll a, ll b)
{
    return b==0? a: gcd(b,a%b);
}

void test()
{
    ll a, b;
    while(cin >> a >> b)
    {
        cout << __gcd(a,b) << endl;
    }
}

void run()
{

}

int main()
{
    test();
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
