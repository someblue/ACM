#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double v,t,a;
    while(cin>>v>>t)
    {
        if(t==0)
        {
            cout<<'0'<<endl;
            continue;
        }
        a=v/t;
        cout<<2*a*t*t<<endl;
    }
    return 0;
}
