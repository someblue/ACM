#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0) break;
        if(lcm(lcm(d,e),f)%gcd(gcd(a,b),c)==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
