#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int intabs(int a)
{
    return a>=0?a:(-a);
}

int main()
{
    int i;
    int r,j,c,n,sz;
    int ans;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&i,&j);
        r=i+j-1;
        c=j;
        if(r>n) c=c-(i+j-n-1);
//        printf("c=%d\n",c);
//        printf("n-intabs(r-n)=%d\n",n-intabs(r-n));
        if(r%2==0)
        {
            sz=n-intabs(r-n);
//            printf("sz=%d\n",sz);
            //c = 1 + n-intabs(r-n) -c;
            c=sz+1-c;
        }
//        printf("r=%d,c=%d\n",r,c);
        ans=0;
        for(i=1;i<r;i++)
        {
            if(i<=n) ans+=i;
            else ans+=2*n-i;
        }
        ans+=c;
        printf("%d\n",ans);
    }
    return 0;
}
