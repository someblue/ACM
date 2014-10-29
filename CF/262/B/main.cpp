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
const int N = 100;
ll a,b,c;
ll getdigit(ll x)
{
    ll res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
ll pow(ll x,ll y)
{
    ll res=1;
    while(y--)
        res*=x;
    return res;
}
ll getx(ll s)
{
    return b*pow(s,a)+c;
}

int main()
{
    vector<ll> ans;
    while(cin>>a>>b>>c)
    {
        ans.clear();
        for(ll i=1;i<=81;++i)
        {
            ll x = getx(i);
            if(x<=0||x>=1e9) continue;
            if(getdigit(x)==i)
                ans.push_back(x);
        }
        if(ans.size()==0)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<ans.size()<<endl;
        cout<<ans[0];
        for(unsigned i = 1;i<ans.size();++i)
            cout<<' '<<ans[i];
        cout<<endl;
    }
    return 0;
}
