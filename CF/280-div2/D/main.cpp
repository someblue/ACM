#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
//const int INF = 1e9;
const double eps = 1e-6;
const int N = 3*1000000;
ll cas = 1;

char s[][10]={"Vanya","Vova","Both"};
int who[N];
ll n,x,y;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

void run()
{
    ll g = gcd(x,y);
    x /= g;
    y /= g;
    ll xy = x+y;
    swap(x,y);
    ll xx = x, yy = y;
    for(ll i = 1; i<=xy ; i++)
    {
        if(xx < yy)
        {
            who[i] = 0;
            xx += x;
        }
        else
        {
            who[i] = 1;
            yy += y;
        }
    }
    ll a;
    for(ll i = 1; i <= n; i ++ )
    {
        scanf("%I64d",&a);
        a %= xy;
        if(a==0 || a==xy-1)
            puts(s[2]);
        else
            puts(s[who[a]]);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%I64d%I64d%I64d",&n,&x,&y)!=EOF)
        run();
    return 0;
}
