#include <iostream>

using namespace std;

int main()
{
    int T,a,b,i;
    long long n[51];
    n[0]=1;n[1]=1;
    for(i=2;i<=50;i++)
    {
        n[i]=n[i-1]+n[i-2];
    }
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        a=b-a;
        cout<<n[a]<<endl;
    }
    return 0;
}
