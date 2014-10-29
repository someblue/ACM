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
    freopen("in","r",stdin);
    long long a,b,l,c,d,cc;
    int t,ti;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        scanf("%lld%lld%lld",&a,&b,&l);
//        d=lcm(a,b);
//        c=lcm(d,l)/d; cc=c;
//        //printf("lcm(%lld,%lld)=%lld\n",a,b,d);
        printf("Case %d: ",ti);
//        while(1)
//        {
//            if(lcm(d,c)>l) {printf("impossible\n");break;}
//            else if(lcm(d,c)==l) {printf("%lld\n",c);break;}
//            c+=cc;
//        }
        d=lcm(a,b);
        if(l%d!=0) {printf("impossible\n");continue;}
        c=l/d;
        printf("%lld\n",c);
    }
    return 0;
}
