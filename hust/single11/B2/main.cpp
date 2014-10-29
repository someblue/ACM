#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 22;
const double pi = acos(-1.0);

struct point
{
    double x,y,a;
    point() {}
    point(double _x,double _y)
    {
        x = _x; y = _y;
    }
    point operator - (point &b)
    {
        return point(x-b.x,y-b.y);
    }
};

double dp[1<<N];
int n;
double l,r;
point p[N];

inline int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

point rotate(point a,double c)
{
    return point(a.x*cos(c)-a.y*sin(c),a.x*sin(c)+a.y*cos(c));
}

double cal(point left,int id)
{
    point d = rotate(left-p[id],p[id].a);
    if(dcmp(d.y)>=0) return r+1.0;
    return p[id].x - p[id].y * d.x / d.y;
}

void run()
{
    for(int i=0;i<n;++i)
        scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].a);
    for(int i=0;i<n;++i)
        p[i].a = p[i].a*pi/180.0;
    dp[0]=l;
    for(int i=1;i<(1<<n);++i)   dp[i]=-100000.0;
    for(int i=0;i<(1<<n);++i)
    {
        if(dp[i]<=-100000.0+eps)    continue;
        for(int j=0;j<n;++j)    if((i & (1<<j)) == 0)
        {
            dp[i|(1<<j)] = max(dp[i|(1<<j)],cal(point(dp[i],0),j));
            if(dcmp(dp[i|(1<<j)]-r)>=0)
            {
                printf("%.9lf\n",r-l);
                return;
            }
        }
    }
    double ans = -1000000.0;
    for(int i=0;i<(1<<n);++i)
        ans = max(ans,dp[i]);
    printf("%.9lf\n",ans-l);
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%lf%lf",&n,&l,&r)!=EOF)
        run();
    return 0;
}
