#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n,t1,t2,i;
    cin>>n;
    cin>>t1;
    for(i=1;i<n;i++)
    {
        cin>>t2;
        t1=gcd(t1,t2);
    }
    cout<<t1;
    return 0;
}
