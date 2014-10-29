#include <iostream>

using namespace std;

int main()
{
    int a,b,n,i,p,ans;
    cin>>n;
    p=0;ans=0;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==-1)
        {
            if(p)
                p--;
            else
                ans++;
        }
        else
            p+=a;
    }
    cout<<ans<<endl;
}
