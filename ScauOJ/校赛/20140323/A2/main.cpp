#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100000

int an[N],bn[N];

using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int _;
    int i,j,n,m;
    long long a,b,g;
    scanf("%d",&_);
    while(_--)
    {
        a=b=1;
        memset(an,0,sizeof(an));
        memset(bn,0,sizeof(bn));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&an[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&bn[i]);
        i=0;
        while(i<n&&i<m)
        {
            a*=an[i];
            b*=bn[i];
            g=gcd(a,b);
            a/=g;
            b/=g;
            i++;
        }
        while(i<n&&b!=1)
        {
            a*=an[i];
            g=gcd(a,b);
            a/=g;
            b/=g;
            i++;
        }
        while(i<m&&a!=1)
        {
            b*=bn[i];
            g=gcd(a,b);
            a/=g;
            b/=g;
            i++;
        }
        if(a==b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
