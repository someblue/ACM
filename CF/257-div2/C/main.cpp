#include <iostream>

using namespace std;

const long long INF = 1e18;
long long ans;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(n<m) swap(n,m);
    if(k>n+m-2) cout<<"-1"<<endl;
    else
    {
        if(n>k) cout<<n/(k+1)*m<<endl;
        else
        {
            k-=n-1;
            cout<<m/(k+1)<<endl;
        }
    }
    return 0;
}
