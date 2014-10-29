#include <iostream>

using namespace std;

int main()
{
    long long a,b,i,ans,ans2;
    while(cin>>a>>b)
    {
        ans2=a;
        for(i=10;;i*=10)
        {
            if((a+1)%i==0)continue;
            ans=(a/i)*i-1;
            if(ans<a-b) break;
            ans2=ans;
        }
        cout<<ans2<<endl;
    }
    return 0;
}
