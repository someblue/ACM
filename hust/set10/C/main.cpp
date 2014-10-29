#include <bits/stdc++.h>

using namespace std;
const int N = 10000;
const int mod = 2009;
int f[N],sum[N];

void make(int n)
{
    f[0]=1;
    f[1]=3;
    f[2]=5;
    for(int i=3;i<=n;++i)
        f[i] = (3*f[i-1]+2*f[i-2]+7*f[n-3])%mod;
    sum[0]=1;
    for(int i=1;i<=n;++i)
        sum[i] = (sum[i-1]+f[i])%mod;
}

int main()
{
    make(1000);
    for(int i=0;i<100;++i)
    {
        if(i%10 == 0)   cout<<endl;
        printf("%6d",f[i]);
    }
    cout<<endl;
    for(int i=0;i<100;++i)
    {
        if(i%10 == 0)   cout<<endl;
        printf("%6d",sum[i]);
    }
    return 0;
}
