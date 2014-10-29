#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 12

using namespace std;

int od[N],ab[N][N];

int main()
{
    int i,j,n,t,maxn=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        od[i]=i;
        for(j=0;j<n;j++)
            scanf("%d",&ab[i][j]);
    }
    do
    {
        t=0;
        for(i=0;i<n;i++)
            t+=ab[i][od[i]];
        if(maxn<t) maxn=t;
    }
    while(next_permutation(od,od+n));
    printf("%d\n",maxn);
    return 0;
}
