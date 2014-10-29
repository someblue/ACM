#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100010

using namespace std;

char s[N];
int pr[110],ans[N];

int ispr(int n)
{
    int i,sqrtn;
    sqrtn=sqrt(n);
    for(i=2;i<=sqrtn;i++)
    {
        if(n%i==0) break;
    }
    return (i<=sqrtn?0:1);
}

void makeprtable()
{
    int i;
    memset(pr,0,sizeof(pr));
    for(i=10;i<100;i++)
        pr[i]=ispr(i);
}

void printprtable()
{
    int i;
    for(i=10;i<100;i++)
        if(pr[i])
            printf("%d\n",i);
}

void deal(int len)
{
    memset(ans,0,sizeof(ans));
    int lastp,ptr,num;
    ans[len-1]=-1;
    for(ptr=len-2,lastp=-1;ptr>=0;ptr--)
    {
        num=(s[ptr]-'0')*10+s[ptr+1]-'0';
        if(pr[num]) lastp=num;
        ans[ptr]=lastp;
    }
}

void printans(int len)
{
    int i;
    for(i=0;i<len;i++)
        printf("%d:%d\n",i+1,ans[i]);
}

int main()
{
    int t,n,len;
    makeprtable();
    //printprtable();
    scanf("%s",s);
    len=strlen(s);
    deal(len);
    //printans(len);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n-1]);
    }
    return 0;
}
