#include <iostream>

using namespace std;

int main()
{
    int i,j,n,ji,ou;
    ji=ou=0;
    for(i=0;i<3;i++)
    {
        cin>>n;
        if(n&1)ji++;
        else ou++;
    }
    if(ji==2&&ou==1)
        cout<<"YES"<<endl;
    else
        cout<<"NOT"<<endl;
    return 0;
}
