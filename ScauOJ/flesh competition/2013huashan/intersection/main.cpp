#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110

using namespace std;

long long lx[N],ly[N],nx[N],ny[N];

int main()
{
    long long mx,my,ans,ans2;
    int i,t,ti,k;
    bool lcre,ncre,cre;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        ans=ans2=0;
        scanf("%d",&k);
        for(i=0;i<k;i++) scanf("%I64d",&lx[i]);
        for(i=0;i<k;i++) scanf("%I64d",&ly[i]);
        for(i=0;i<k;i++) scanf("%I64d",&nx[i]);
        for(i=0;i<k;i++) scanf("%I64d",&ny[i]);
        for(i=0;i<k;i++)
        {
            lcre=ncre=0;
            if(lx[i]>ly[i]) {swap(lx[i],ly[i]);lcre=1;}
            if(nx[i]>ny[i]) {swap(nx[i],ny[i]);ncre=1;}
            cre=lcre^ncre;
            mx=max(lx[i],nx[i]);
            my=min(ly[i],ny[i]);
            if(my<mx) {ans=-1;break;}  //-----bug-----
            if(cre) ans+=my-mx;
            else ans2+=my-mx;
        }
        if(ans!=-1)
            ans=max(ans,ans2);
        else
            ans=0;
        printf("Case %d: %I64d\n",ti,ans);
    }
    return 0;
}
