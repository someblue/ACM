#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    a=max(a,b);
    a=6-a+1;
    b=6/gcd(a,6);
    a=a/gcd(a,6);
    cout<<a<<'/'<<b<<endl;
    return 0;
}
