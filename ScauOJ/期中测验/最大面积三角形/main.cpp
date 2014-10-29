#include <iostream>
#include <cstdio>
#include <cmath>
#define POW2(x) (x)*(x)

using namespace std;

int main()
{
    double x[55],y[55],p,s,ans=0,la,lb,lc;
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            for(k=j+1;k<n;k++)
            {
                la=sqrt(POW2(x[i]-x[j])+POW2(y[i]-y[j]));
                lb=sqrt(POW2(x[i]-x[k])+POW2(y[i]-y[k]));
                lc=sqrt(POW2(x[k]-x[j])+POW2(y[k]-y[j]));
                p=(la+lb+lc)/2;
                s=sqrt(p*(p-la)*(p-lb)*(p-lc));
                if(ans<s)
                    ans=s;
            }
    printf("%.4lf",ans);
    return 0;
}
