#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,i;
    double ans,n,r;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>r;
        for(i=0;i<6;i++)
        {
            cin>>n;
            ans+=(n*r)/2;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
