#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1000000

using namespace std;

bool num[MAX+10];
int p[MAX+10],mp[MAX+10],pp,pmp;

void table()
{
    memset(num,0,sizeof(num));
    pp=2;pmp=0;
    p[0]=2;p[1]=3;
    num[2]=num[3]=1;
    int i,j,flag,n,mn;
    double sqrtn;
    for(i=2;p[pp-1]<MAX;i++)
    {
        //------------------6n-1------------------
        flag=1;
        n=6*(i-1)-1;
        sqrtn=sqrt((double)n);
        for(j=0;p[j]<=sqrtn;j++)
            if(n%p[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            p[pp]=n;
            num[n]=1;
            pp++;
        }
        //------------------6n+1------------------
        flag=1;
        n=6*(i-1)+1;
        sqrtn=sqrt((double)n);
        for(j=0;p[j]<=sqrtn;j++)
            if(n%p[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            p[pp]=n;
            num[n]=1;
            pp++;
        }
    }
    for(i=0;i<pp-1;i++)
    {
        n=p[i];
        mn=0;
        while(n!=0)
        {
            mn+=n%10;
            n/=10;
        }
        if(num[mn])
            mp[pmp++]=p[i];
    }
}

int main()
{
    table();
    int ans,T,l,r;
    int i,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d",&l,&r);
        ans=0;
        for(j=0;mp[j]<l;j++);
        for(;mp[j]<=r;j++)
            ans++;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
