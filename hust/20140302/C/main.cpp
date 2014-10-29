#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 110

using namespace std;

int prime[N*N+N*N],tab[N*2][N*2];

int isprime(int n)
{
    int i,sqrtn;
    sqrtn=sqrt(n);
    for(i=2;i<=sqrtn;i++)
        if(n%i==0)
            break;
    if(i<=sqrtn) return 0;
    if(n%4==3) return 2;
    return 1;
}

void make_prime()
{
    int i;
    prime[0]=0;prime[1]=1;
    for(i=2;i<=20000;i++)
        prime[i]=isprime(i);
}

void print_prime()
{
    int i;
    cout<<"prime:";
    for(i=0;i<=100;i++)
        if(prime[i]>0)
            printf("%d ",i);
    cout<<endl;

    cout<<"1:";
    for(i=0;i<=100;i++)
        if(prime[i]==1)
            printf("%d ",i);
    cout<<endl;

    cout<<"2:";
    for(i=0;i<=100;i++)
        if(prime[i]==2)
            printf("%d ",i);
    cout<<endl;
}

void getin(int x,int y,int times)
{
    tab[x+100][y+100]=1;
    tab[x+100][-y+100]=1;
    tab[-x+100][y+100]=1;
    tab[-x+100][-y+100]=1;
    if(times==0) getin(y,x,1);
}

void make_tab()
{
    memset(prime,0,sizeof(prime));
    memset(tab,0,sizeof(tab));
    make_prime();
    //print_prime();
    int x,y;

    x=0;
    for(y=0;y<=100;y++)
        if(prime[y]==2)
            getin(x,y,0);

    for(x=1;x<=100;x++)
    {
        for(y=x;y<=100;y++)
        {
            if(prime[x*x+y*y]==1)
                getin(x,y,0);
        }
    }
}

int solve(int x1,int x2,int y1,int y2)
{
    int i,j,ans;
    x1+=100;x2+=100;y1+=100;y2+=100;ans=0;
    for(i=x1;i<=x2;i++)
    {
        for(j=y1;j<=y2;j++)
        {
            ans+=tab[i][j];
        }
    }
    return ans;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    freopen("in","r",stdin);
    make_tab();
    int x1,x2,y1,y2,t;
    int n1,n2,g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        n1=solve(x1,x2,y1,y2);
        n2=(x2-x1+1)*(y2-y1+1);
        g=gcd(n1,n2);
        //printf("%d/%d\n",solve(x1,x2,y1,y2),(x2-x1+1)*(y2-y1+1));
        printf("%d/%d\n",n1/g,n2/g);
    }
    return 0;
}
