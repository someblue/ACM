#include <cstdio>
#define N 100010

int num[N];

int main()
{
    int T,Ti,n,i,p,q,first,t,maxn,maxp,maxq,allfu;
    scanf("%d",&T);
    for(Ti=1;Ti<=T;Ti++)
    {
        if(Ti>1) printf("\n");
        allfu=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            if(allfu&&num[i]>0)
                allfu=0;
        }
        if(allfu)
        {
            maxn=num[0];maxp=0;
            for(i=1;i<n;i++)
                if(maxn<num[i])
                {
                    maxn=num[i];maxp=i;
                }
            printf("Case %d:\n%d %d %d\n",Ti,maxn,maxp+1,maxp+1);
            continue;
        }
        p=-1;maxn=0;
        while(num[++p]<0);
        while(p<n)
        {
            first=-1;t=0;q=p;
            while(t>=0&&q<n)
            {
                if((first==-1&&num[q]<0)||q>=n-1)
                    first=q;
                t+=num[q];
                if(t>maxn){maxn=t;maxp=p;maxq=q;}
                q++;
            }
            if(first>0)
                p=first;
            p++;
        }
        printf("Case %d:\n%d %d %d\n",Ti,maxn,maxp+1,maxq+1);
    }
    return 0;
}
