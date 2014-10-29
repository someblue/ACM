#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1010

using namespace std;

struct node{
    int a,b;
    friend bool operator < (node a,node b)
    {
        return a.b>b.b;
    }
};

node s[N];

int main()
{
    int n,i,sumt,maxt,ti=0;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++) scanf("%d%d",&s[i].a,&s[i].b);
        sort(s,s+n);
        sumt=0;maxt=0;
        for(i=0;i<n;i++)
        {
            sumt+=s[i].a;
            maxt=max(maxt,sumt+s[i].b);
        }
        printf("Case %d: %d\n",++ti,maxt);
    }
    return 0;
}
