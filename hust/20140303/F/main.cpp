#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long ans,n,k;
    while(1)
    //while(scanf("%I64d",&n)!=EOF)
    {
        cin>>n;
        if(cin.eof()) break;
        ans=1;
        k=1;
        while(1)
            if((k=(k<<1))>n)
            {
                cout<<ans<<endl;
                break;
            }
            else
                ans++;
    }
    return 0;
}
