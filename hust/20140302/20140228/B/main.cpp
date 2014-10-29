#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 25

using namespace std;

struct can
{
    int a,b;
    friend bool operator < (can a,can b)
    {
        return a.b>b.b;
    }
}

can c[N];

int main()
{
    int n,m,i,j;
    long long ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&c[i].a,&c[i].b);
    }
    sort(c,c+m);
    ans=0;
    for(i=0;i<m;i++)
    {
        if(n>=c[i].a)
        {
            n-=c[i].a;
            ans+=c[i].a*c[i].b;
        }
    }
    return 0;
}
