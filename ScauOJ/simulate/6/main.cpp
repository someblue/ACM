#include <iostream>

using namespace std;

int main()
{
    double a,b,c,r;
    cin>>a>>b>>c>>r;
    r*=2;
    if(r<=a&&r<=b&&r<=c)
        cout<<'Y'<<endl;
    else
        cout<<'N'<<endl;
    return 0;
}
