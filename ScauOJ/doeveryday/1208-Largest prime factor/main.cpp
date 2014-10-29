#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define N 1000010

using namespace std;

int prime[N],position[N];

int main()
{
    int n,i,j,sqrtn,lastp;
    memset(prime,0,sizeof(prime));
    sqrtn=sqrt((double)N);
    prime[0]=prime[1]=1;
    position[0]=position[1]=0;
    lastp=0;
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            position[i]=lastp;
            continue;
        }
        position[i]=++lastp;
        prime[i]=i;
        for(j=i*2;j<N;j+=i)
            prime[j]=i;
    }
    while(cin>>n,n!=-1)
    for(i=n-100;i<=n;i++)
        printf("%d:%d,%d\n",i,prime[i],position[i]);
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",position[prime[n]]);
    return 0;
}
