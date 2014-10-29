#include <iostream>

using namespace std;

int main()
{
    int a,b,c,sum,num_case,num_farmer;
    cin>>num_case;
    while(num_case--)
    {
        cin>>num_farmer;
        sum=0;
        while(num_farmer--)
        {
            cin>>a>>b>>c;
            sum += a*c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
