#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

long long num[N],num2[N];

int main()
{
    int T,n,p1,p2,i,cnt;
    long long k,sum,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%I64d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%I64d",&num2[i]);
        sort(num2,num2+n);
        num[0]=num2[0];cnt=1;
        for(i=1;i<n;i++)
        {
            if(num2[i]==num[cnt-1]) continue;
            num[cnt++]=num2[i];
        }
        p1=0;p2=cnt-1;ans=0;
        while(p1<p2)
        {
            sum=num[p1]+num[p2];
            if(sum==k)
            {
                ans+=2;
                p1++;p2--;
            }
            else if(sum<k)
                p1++;
            else
                p2--;
        }
        if(p1==p2&&num[p1]+num[p2]==k)
            ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}
