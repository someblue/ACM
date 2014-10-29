#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20010
#define K 12
#define MOD 1000000000

using namespace std;

long long l[N][K],a[N];

void print(int n,int k)
{
    int i,j;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
            printf("%lld ",l[j][i]);
        cout<<endl;
    }
}

int main()
{
    freopen("in","r",stdin);
    memset(l,0,sizeof(l));
    memset(a,0,sizeof(a));
    int n,k,i,j,m;//i for k, j for n;  l[j][i];
    long long temp,ans;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1,j=1;j<=n;j++)
        l[j][i]=1;
    for(i=2;i<=k;i++)
    {
        for(j=n-i+1;j>k-i;j--)
        {
            temp=0;
            int top=n-i+2,i2=i-1;
            for(m=j+1;m<=top;m++)
            {
                if(a[j]>a[m])
                    temp+=l[m][i2];
            }
            l[j][i]=temp%MOD;
        }
    }
    ans=0;
    for(i=k,j=1;j<=n-k+1;j++)
        ans+=l[j][i];
    ans%=MOD;
    printf("%lld\n",ans);
    print(n,k);
    return 0;
}
