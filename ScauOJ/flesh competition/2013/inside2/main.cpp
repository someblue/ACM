#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 510

using namespace std;

int main()
{
    int n,v[N],ans,i,j,l,r;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        sort(v,v+n);
        ans=n;
        l=0;r=(n+2-(n&1))/2-1;
        //printf("l=%d,r=%d\n",l,r);
        for(;r<n;r++)
        {
            if(v[r]/v[l]>=3)
            {
                ans--;l++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
