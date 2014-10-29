#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a,b,d1,d2,m1,m2,sum;
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%I64d%I64d",&a,&b);
        d1=a/3;m1=a%3;
        d2=b/3;m2=b%3;
        sum=(d2-d1)*2;
        if(m1)sum--;
        sum++;
        if(m2==2)sum++;
        printf("Case %d: %I64d\n",i,sum);
    }
    return 0;
}
