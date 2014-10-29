#include <iostream>

using namespace std;

int main()
{
    int max,n;
    cin>>n;
    max=n%10;
    while(n!=0)
    {
        if(max<n%10)
            max=n%10;
        n/=10;
    }
    cout<<max;
    return 0;
}
