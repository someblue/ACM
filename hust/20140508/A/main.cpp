#include <iostream>

using namespace std;

int main()
{
    int n,k,p;
    int i,j;
    cin>>n>>p>>k;
    string s;
    if(p-k>1)
    {
        cout<<"<< ";
        for(i=p-k;i<p;i++)
            cout<<i<<" ";
    }
    else
    {
        for(i=1;i<p;i++)
            cout<<i<<" ";
    }
    cout<<"("<<p<<") ";
    if(p+k<n)
    {
        for(i=p+1;i<=p+k;i++)
            cout<<i<<" ";
        cout<<">>"<<endl;
    }
    else
    {
        for(i=p+1;i<n;i++)
            cout<<i<<" ";
        if(p!=n)
            cout<<n<<endl;
    }
    return 0;
}
