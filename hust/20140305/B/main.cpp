#include <iostream>

using namespace std;

int main()
{
    int n,k,t,tot;
    cin>>n>>k>>t;
    tot=n*k*t/100;
    int i;
    for(i=0;i<n;i++)
    {
        if(tot>k)
        {
            cout<<k<<' ';
            tot -= k;
        }
        else
        {
            cout<<tot<<' ';
            tot=0;
        }
    }
    return 0;
}
