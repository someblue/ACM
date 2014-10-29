#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n%(m+1)==0)
            cout<<"none"<<endl;
        else if(n<=m)
        {
            cout<<n;
            for(int i=n+1;i<=m;++i)
                cout<<' '<<i;
            cout<<endl;
        }
        else
            cout<<n%(m+1)<<endl;
    }
    return 0;
}
