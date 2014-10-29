#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20

using namespace std;

struct _song{
    int d,t;
    friend bool operator < (_song a,_song b)
    {
        return a.t<b.t||(a.t==b.t&&a.d<b.d);
    }
}s[N];

bool vis[N];

int main()
{
    int n,t,i,j,k,ans,num,mint,mini,sumt,tone;
    bool emp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",&s[i].d);
        for(i=0;i<n;i++)scanf("%d",&s[i].t);
        scanf("%d",&t);
        sort(s,s+n);
        ans=0;
        for(i=0;i<n;i++)
        {
            //printf("%d\n",i);
            memset(vis,0,sizeof(vis));
            num=0;sumt=s[i].d;tone=s[i].t;
            while(sumt<=t)
            {
                num++;
                mint=100000000;emp=1;
                for(j=i+1;j<n;j++)//find min
                {
                    if(!vis[j]&&mint>=s[j].d+(s[j].t>tone?s[j].t-tone:0))
                    {
                        mint=s[j].d+(s[j].t>tone?s[j].t-tone:0);
                        mini=j;
                        emp=0;
                    }
                }
                if(emp) break;
                if(s[mini].t>tone) tone=s[mini].t;
                vis[mini]=1;
                sumt+=mint;
                //printf("mint:%d,mini:%d,sumt:%d\n",mint,mini,sumt);
            }
            ans=max(num,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
