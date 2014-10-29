#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
typedef long long ll;
using namespace std;

ll I[N],T[N];

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ll a=1,b=1,n,m,i,j,g;
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<n;i++) scanf("%I64d",&I[i]);
    for(i=0;i<m;i++) scanf("%I64d",&T[i]);
    for(i=0;i<n||i<m;i++)
    {
        if(i<n) a*=I[i];
        if(i<m) b*=T[i];
        g=gcd(a,b);
        a/=g;b/=g;
    }
    //printf("%I64d %I64d",a,b);
    printf("%s\n",a%b?"no":"yes");
    return 0;
}

/*
AC
*/
