#include <iostream>

using namespace std;

int J(const int n)
{
    long long k;
    for(k=1;k<=n;k=(k<<1));
    k=(k>>1);
    return 2*(n-k)+1;
}

int main()
{
    ios::sync_with_stdio(0);
    int m,n,i,t;
    while(cin>>n>>m,m!=0)
    {
        t=n;
        for(i=0;i<m;i++)
        {
            t=J(t);
        }
        cout<<t<<endl;
    }
    return 0;
}
