#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
#define EN 20010
#define MOD 10000

using namespace std;

bool e[EN];
int x[N],d[N],n;

bool exist(int k,int &b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(x[i]==k) return b=i,1;
    }
    return 0;
}
void recordExist()
{
    int i;
    for(i=0;i<n;i++) e[x[i]+MOD]=1;
}

int main()
{
    memset(e,0,sizeof(e));
    int i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&x[i],&d[i]);
    recordExist();
    for(i=0;i<n;i++)
    {
        a=x[i];
        if(exist(x[i]+d[i],b)&&a==x[b]+d[b]) break;
    }
    printf("%s\n",i<n?"YES":"NO");
    return 0;
}
