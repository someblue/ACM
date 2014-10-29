#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 50010
#define M 500010

using namespace std;

struct node{
    int l,r;
    unsigned c;
    friend bool operator < (node a,node b)
    {
        return a.c<b.c;
    }
};

node line[M];
unsigned char s[N];

int main()
{
    freopen("in","r",stdin);
    int i;
    int n,m,t,ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,n+1);ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&line[i].l,&line[i].r,&t);
            line[i].c=(unsigned char)t;
        }
        sort(line,line+m);
        for(i=0;i<m;i++)
        {
            memset(s+line[i].l,line[i].c,line[i].r-line[i].l);
        }
        for(i=0;i<=n;i++)
        {
//            printf("%d ",s[i]);
            ans+=s[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
