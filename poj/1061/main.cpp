#include <iostream>
using namespace std;
typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)    return -1;
    if(b==0) {x=1;y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}

int main()
{
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    ll a,b,c,x0,y0;
    a = n-m;
    b = l;
    c = x-y;
//    cout<<a<<' '<<b<<' '<<c<<endl;
    ll g = exgcd(a,b,x0,y0);
//    cout<<c<<' '<<g<<endl;
    if(c%g != 0) cout<<"Impossible"<<endl;
    else
    {
        a/=g;
        b/=g;
        c/=g;
        exgcd(a,b,x0,y0);
        ll t = c*x0/b;
        x0 = c*x0-t*b;
        if(x0<0) x0+=b;
        cout<<x0<<endl;
    }
    return 0;
}
