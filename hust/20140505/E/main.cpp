#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000010
typedef long long ll;
using namespace std;
ll num[N];
int main()
{
    ll n,m,i,l,r;
    ll res;
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<n;i++)    scanf("%I64d",&num[i]);
    l=0;r=n-1;res=0;
    while(l+2*m<r)
    {
        res+=num[r]-num[l];
        l+=m;r-=m;
    }
    res+=num[r]-num[l];
    printf("%I64d\n",res*2);
    return 0;
}
