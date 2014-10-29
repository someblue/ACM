#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;
int dp,dps;

int main()
{
    int _,n,cas=1;
    int i,ans,s,t,num;
    bool fir=1;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ans=-11111;
        dp=-11111;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            if(dp>=0)
                dp+=num;
            else
                dp=num,dps=i;
            if(ans<dp)
            {
                ans=dp;
                s=dps;
                t=i;
            }
        }
        if(fir) fir=0;
        else printf("\n");
        printf("Case %d:\n%d %d %d\n",cas++,ans,s,t);
    }
    return 0;
}
