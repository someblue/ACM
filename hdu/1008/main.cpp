#include <iostream>

using namespace std;

int main()
{
    int n,a,b,i,ans;
    while(cin>>n&&n)
    {
        ans=n*5;a=0;
        for(i=0;i<n;i++)
        {
            cin>>b;
            if(b>=a) ans+=(b-a)*6;
            else ans+=(a-b)*4;
            a=b;
        }
        cout<<ans<<endl;
    }
    return 0;
}
