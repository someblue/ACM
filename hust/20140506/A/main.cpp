#include <iostream>
using namespace std;

int main()
{
    int n,s,mx,sum,t;
    int i;
    cin>>n>>s;
    for(i=0,sum=0,mx=-1;i<n;i++)
    {
        cin>>t;
        sum+=t;
        if(mx<t) mx=t;
    }
    if(sum-mx<=s)    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
