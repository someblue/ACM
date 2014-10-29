#include <iostream>

using namespace std;

int main()
{
    int n,ans;
    cin>>n;
    if(n==2)
        ans=4;
    else if(n%2)
        ans=(n*n+1)/2;
    else
        ans=n*n/2;
    cout<<ans<<endl;
    return 0;
}
