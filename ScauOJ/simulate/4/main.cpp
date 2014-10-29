#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int m,n,t;
    char c;
    cin>>m>>c>>n;
    if(m<n){t=m;m=n;n=t;}
    cout<<gcd(m,n)<<endl;
    return 0;
}
