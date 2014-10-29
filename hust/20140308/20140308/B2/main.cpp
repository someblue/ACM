#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    printf("%lld\n%lld\n",lcm(70,147),lcm(70,21));
    long long m,n,a,b,l;
    int t,ti;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        scanf("%lld%lld%lld",&m,&n,&l);
        a = lcm(m,n);
        b = l/a;
        printf("Case %d: ",ti);
        if(l%a==0) printf("%lld\n",b);
        else printf("impossible\n");
    }
    return 0;
}
