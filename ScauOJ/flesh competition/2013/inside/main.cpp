#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 510

using namespace std;

int main()
{
    int n,v[N],ans,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        sort(v,v+n);
        ans=n;
        for(i=0;i<n;i++)
        {
            if(!v[i]) continue;
            for(j=i+1;j<n;j++)
            {
                if(!v[j]) continue;
                if(v[j]/v[i]>=3)
                {
                    ans--;
                    v[i]=v[j]=0;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
