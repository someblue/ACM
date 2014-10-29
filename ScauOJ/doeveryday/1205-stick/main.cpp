#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 5010

using namespace std;

struct lw{
    int l,w;
    friend bool operator < (lw a,lw b)
    {
        return (a.l<b.l||(a.l==b.l&&a.w<=b.w));
    }
    friend bool operator <= (lw a,lw b)
    {
        return a.l<=b.l&&a.w<=b.w;
    }
};

lw num[N],sequ[N];

int main()
{
    int T,n,ans,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&num[i].l,&num[i].w);
        sort(num,num+n);
        sequ[0]=num[n-1];
        ans=1;
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<ans;j++)
            {
                if(num[i]<=sequ[j])
                {
                    sequ[j]=num[i];
                    break;
                }
            }
            if(j==ans)
                sequ[ans++]=num[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
