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
const int INF=1<<30;
const double eps=1e-6;
const int mod = 10007;

long long n,inv6;

void getinv()
{
    for(inv6=1;;++inv6)
        if(6*inv6 % mod==1) return;
}

long long cal(long long x)
{
//    cout<<(x*inv6%mod)<<endl;
//    cout<<((x+1)*inv6%mod)<<endl;
//    cout<<((x+2)*inv6%mod)<<endl;
//    return (x*inv6%mod)*(x*inv6%mod)*((x+1)*inv6%mod)*((x+2)*inv6%mod);
    return (x*x*(x+1)*(x+2)*inv6)%mod;
}

void run()
{
    int i;
    long long res=0;
    for(i=0;n;i++)
    {
        long long m=min(n,1LL<<i);
        res=(res+cal(m));
        n-=m;
    }
    res%=mod;
    cout<<res<<endl;
}

void text()
{
    int m;
    while(cin>>m)   cout<<cal(m)<<endl;
}

int main()
{
//    freopen("case.txt","r",stdin);
    getinv();
//    cout<<inv6<<endl;
//    text();
    while(cin>>n)
        run();
    return 0;
}
