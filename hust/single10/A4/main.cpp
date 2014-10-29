#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define PI 3.14159265
using namespace std;
#define eps 0.00000001
struct point
{
    double x,y;
};
point p[1000];
int pn;
bool cmp(point a,point b)
{
    if(a.x==b.x)return a.y+eps<b.y;
    return a.x+eps<b.x;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t,n,r,i,x1,x2,y1,y2,cas=1;
    double z1,z2,ans,now;
    scanf("%d",&t);
    while(t--)
    {
        ans=360.0;
        pn=0;
        scanf("%d%d",&n,&r);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            z1=atan2(y1,x1);
            z2=atan2(y2,x2);
            z1=z1*180.0/PI,z2=z2*180.0/PI;
            if(z1<0)
            z1+=360.0;
            if(z2<0)
            z2+=360.0;
            if(z1+eps<z2)
            {
                swap(z1,z2);
            }
            if(z1-z2<180.0+eps)
            {
                p[pn].x=z2;
                p[pn].y=z1;
                pn++;
            }
            else
            {
                p[pn].x=0.0;
                p[pn].y=z2;
                pn++;

                p[pn].x=z1;
                p[pn].y=360.0;
                pn++;
            }
        }
        sort(p,p+pn,cmp);
        now=0;
        for(i=0;i<pn;i++)
        {
            if(p[i].y+eps<now)
            {
                continue;
            }
            else
            {
                    ans-=p[i].y-max(now,p[i].x);
                    now=p[i].y;
            }
        }
        if(ans<0.0)
        ans=0.0;
        printf("Case %d: %.2lf%\n",cas++,ans*100.0/360.0);
    }
}
