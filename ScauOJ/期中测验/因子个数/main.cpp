#include <iostream>

using namespace std;

int main()
{
    int n,sum=0,i,up;
    cin>>n;
    up=n/2;
    for(i=1;i<=up;i++)
        if(n%i==0)
        {
            //cout<<i<<endl;
            sum++;
        }
    sum++;
    cout<<sum<<endl;
    return 0;
}
