#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100010
using namespace std;
long long c[N],n,x;

int main()
{
    scanf("%I64d%I64d",&n,&x);
    int i;
    long long ans;
    ans=0;
    for(i=0;i<n;i++) scanf("%I64d",&c[i]);
    sort(c,c+n);
    for(i=0;x>1&&i<n;i++,x--)
        ans+=x*c[i];
    if(i<n && x==1)
    {
        long long t=0;
        for(;i<n;i++) t+=c[i];
        ans += t;
    }
    printf("%I64d\n",ans);
    return 0;
}
