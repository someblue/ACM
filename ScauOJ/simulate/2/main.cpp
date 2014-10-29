#include <iostream>

using namespace std;

int main()
{
    int i,n,res=1;
    cin>>n;
    for(i=1;i<=n;i++)
        res*=i;
    cout<<res;
    return 0;
}
