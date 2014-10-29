#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,tot,quetime,intime,usetime;
    int i;
    tot=0;quetime=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&intime,&usetime);
        if(intime>quetime)
        {
            quetime = intime+usetime;
        }
        else
        {
            tot += quetime - intime;
            quetime += usetime;
        }
    }
    printf("%lf\n",(1.0*tot)/n);
    return 0;
}
