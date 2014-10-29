#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 5010

using namespace std;

int slr[N];

int binary(int s,int e,int n)
{
    int m=(s+e)/2;
    if(n>=slr[m]&&n<slr[m+1])
        return m;
    if(n<slr[m])
        return binary(s,m,n);
    else
        return binary(m,e,n);
}

int main()
{
    int T,n,m,i,subscp,ans,expslr;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&slr[i]);
        sort(slr,slr+n);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&expslr);
            if(expslr>=slr[n-1]) ans=slr[n-1];
            else if(expslr<=slr[0]) ans=slr[0];
            else
            {
                subscp=binary(0,n,expslr);
                if((expslr-slr[subscp])<=(slr[subscp+1]-expslr))
                    ans=slr[subscp];
                else
                    ans=slr[subscp+1];
            }
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
