#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool b[100];

int main()
{
    int T,n,cnt,p,p2,no=1;
    double ans;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        ans=0;
        p=0;
        scanf("%d",&n);
        while(n!=0)
        {
            b[cnt++]=n%2;
            n/=2;
        }
        b[cnt++]=0;
//        for(i=cnt-1; i>=0; i--)
//            cout<<b[i];
//        cout<<endl;
        for(i=0; i<=cnt; i++)
        {
            if(b[i]==1&&b[i+1]==0)
            {
                p=i;
                break;
            }
        }
        b[p+1]=1;
        b[p--]=0;
        p2=0;
        while(b[p2]==0&&b[p]==1&&p>p2)
        {
            b[p--]=0;
            b[p2++]=1;
        }
//        for(i=cnt-1; i>=0; i--)
//            cout<<b[i];
//        cout<<endl;
        for(i=0; i<cnt; i++)
            if(b[i])
                ans+=pow(2.0,i);
        printf("Case %d: %.0lf\n",no++,ans);
    }
    return 0;
}
