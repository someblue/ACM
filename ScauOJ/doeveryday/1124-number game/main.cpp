#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    double n,m,k,x,y,t;
    int T,cnt=1,kint;
    cin>>T;
    while(T--)
    {
        cin>>n;
        k=ceil(sqrt(n));
        m=k*k-k+1;
        if(n==m)
            x=y=k;
        else if(n<m)
        {
            x=n-(k-1)*(k-1);
            y=k;
        }
        else
        {
            x=k;
            y=k*k-n+1;
        }
        kint=(int)k;
        if(kint&1)
        {
            t=x;
            x=y;
            y=t;
        }
        printf("Case %d: %.0lf %.0lf\n",cnt++,x,y);
    }
    return 0;
}
