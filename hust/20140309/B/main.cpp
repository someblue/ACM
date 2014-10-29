#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 35
typedef long long ll;
using namespace std;
int w[N];
void run()
{
    int t,cas=1;
    int i;
    int n,p,q,totw,ans;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",cas++);
        scanf("%d%d%d",&n,&p,&q);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        totw=0;ans=0;
        for(i=0;i<n;i++)
        {
            totw+=w[i];
            if(totw>q) break;
            ans++;
            if(ans>p) {ans--;break;}
        }
        printf("%d\n",ans);
    }
}
int main()
{
    run();
    return 0;
}
