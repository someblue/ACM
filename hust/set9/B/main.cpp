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
    ll A,B,C,k,m;
    ll a,b,c,x,y;
    while(cin>>A>>B>>C>>k)
    {
        if(A==0 && B==0 && C==0 && k==0)
            break;
        if(A==B)
        {
            cout<<"0"<<endl;
            continue;
        }
        m = 1LL << k;
        a = C;
        b = m;
        c = B-A;
        ll g = exgcd(a,b,x,y);
        if(c%g!=0)
        {
            cout<<"FOREVER"<<endl;
            continue;
        }
//        a/=g;
//        b/=g;
//        c/=g;
        exgcd(a,b,x,y);
        x=(x*(c/g))%b;  //方程ax=b(mod n)的最小解
        x=(x%(b/g)+b/g)%(b/g);  //方程ax=b(mod n)的最整数小解
        cout<<x<<endl;
    }
    return 0;
}
