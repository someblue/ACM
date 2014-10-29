#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

inline int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int n,*num,i,p1,p2,ans,key;
    while(scanf("%d",&n),n!=0)
    {
        num=(int*)malloc(n*sizeof(int));
        ans=0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);

        for(i=0;i<n-1;i++)
        {
            p1=n-1;p2=i+1;
            while(p1>=p2)
            {
                key=max(num[i]+num[p1]+n-p1+i,num[i]+num[p2]+p2-i);
                ans=max(ans,key);
                p1--;p2++;
            }
        }
        printf("%d\n",ans);
        free(num);
    }
    return 0;
}
