#include <iostream>

using namespace std;


int main()
{
    int n;
    int a,b;
    int ans = 0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(b-a>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
