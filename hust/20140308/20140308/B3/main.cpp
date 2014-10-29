#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10000

using namespace std;

long long prime[N];
int fact[2][N];
int cnt,top;

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

inline bool isp(int n)
{
    int i;
    for(i=0;i<cnt;i++)
        if(n%prime[i]==0) return 0;
    return 1;
}

void prime_table()
{
    memset(prime,0,sizeof(prime));
    prime[0]=2;
    cnt=1;
    long long num;
    num=3;
    while(1)
    {
        if(isp(num))
        {
            prime[cnt++]=num;
            if(cnt>=N) break;
        }
        num++;
    }
}

void make_fact(int id,int n)
{
    int i;
    i=0;
    while(i<N-1)
    {
        if(n%prime[i]) i++;
        else
        {
            fact[id][i]++;
            n/=prime[i];
            if(n==1) break;
        }
    }
    if(id==1) top=i;
}

inline long long lpow(long long b,int p)
{
    long long res=1;
    while(p--) res*=b;
    return res;
}

long long getb()
{
    long long res=1;
    int i;
    for(i=0;i<=top;i++)
    {
        if(fact[1][i]>fact[0][i])
            res *= lpow(prime[i],fact[1][i]);
    }
    return res;
}

void run()
{
    int t,ti;
    long long m,n,l,a;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        scanf("%lld%lld%lld",&m,&n,&l);
        a=lcm(m,n);
        if(l%a!=0){printf("impossible\n");continue;}
        memset(fact,0,sizeof(fact));
        make_fact(0,a);
        make_fact(1,l);
        printf("Case %d: ",ti);
        printf("%lld\n",getb());
    }
}

int main()
{
    prime_table();
    run();
    //cout<<prime[]<<endl;
    return 0;
}
