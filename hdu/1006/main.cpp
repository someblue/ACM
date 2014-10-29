#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool judge(double m,double s,double d)
{
    d = d/360 * 60;
    return m>=d && s>=d && m<=60.0-d && s<=60.0-d && fabs(m-s)>=d;
//    return m>d && s>d && m<60.0-d && s<60.0-d && fabs(m-s)>d;
}

int main()
{
    double d;
    while(scanf("%lf",&d)!=EOF&&d!=-1.0)
    {
        if(d==0.0){printf("100.000\n");continue;}
        if(d>=120.0){printf("0.000\n");continue;}
        int res=0;
        int m,s;
        for(m=0;m<60;m++)
        {
            for(s=0;s<60;s++)
            {
                res+=judge((double)m,(double)s,d);
            }
        }
        cout<<res<<endl;
        printf("%.3lf\n",res*1.0/3600.0*100.0);
    }
    return 0;
}
