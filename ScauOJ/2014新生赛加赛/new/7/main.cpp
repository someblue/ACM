#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010

using namespace std;

int k[N];

struct node{
    int num[N];
    friend bool operator < (node a,node b)
    {
        int i=0;
        for(;;i++)
        {
            if(a.num[k[i]]!=b.num[k[i]])
                return a.num[k[i]]<b.num[k[i]];
        }
    }
};

node thing[N];

void text()
{
    int a,b;
    while(scanf("%d%d",&a,&b))
    {
        printf("%d\n",thing[a]<thing[b]);
    }
}

int main()
{
    int n,m,klen;
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<=n;j++)
            {
                scanf("%d",&thing[i].num[j]);
            }
        }
        scanf("%d",&klen);
        for(i=0;i<klen;i++)
            scanf("%d",&k[i]);
        k[klen]=0;
//        text();
        sort(thing,thing+m);
        for(i=0;i<m;i++)
            printf("%d ",thing[i].num[0]);
        printf("\n");
    }
    return 0;
}
