#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010;

int a[N],n,k;

inline bool cmp(const int a, const int b)
{
    return a>b;
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int i,j;
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n,cmp);
        int p=0;
        int ans = 0;
        while(p<n)
        {
            ans += a[p]*2-2;
            p+=k;
        }
        printf("%d\n",ans);
    }

    return 0;
}
