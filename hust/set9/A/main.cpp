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
const ll mod = 9973;

bool isprm(int x)
{
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}

ll inv(ll a,ll m)
{
    if(a==1)    return 1;
    return inv(m%a,m)*(m-m/a)%m;
}

void run()
{
    ll n,b,invb;
    cin>>n>>b;
    b %= mod;
    invb = inv(b,mod);
    cout<<invb%mod * n %mod<<endl;
}

int main()
{
//    freopen("case.txt","r",stdin);

    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
