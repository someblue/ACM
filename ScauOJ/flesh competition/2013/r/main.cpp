#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

inline double intl(double n)
{
    double t=n-floor(n+0.5);
    return (t<0.0001&&t>-0.0001)?floor(n+0.5):n;
}

int main()
{
    int t,i;
    double n,r,ans;
    const double pi=3.141592654;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%lf",&n,&r);
        if(n==1)
        {
            printf("Case %d: %.0lf\n",i,r);
            continue;
        }
        ans=r/sin(pi/n)+r;
        //scanf("%lf",&ans);
        //printf("%lf\n",ans);
        ans=ceil(intl(ans));
        printf("Case %d: %.0lf\n",i,ans);
    }
    return 0;
}

//好好反省精度问题
