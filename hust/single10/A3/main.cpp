#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double DB;
typedef pair<DB,DB> pdd;
typedef pdd point;
#define x first
#define y second
const DB eps = 1e-8;
const DB pi = acos(-1.0);
const int N = 1005;
pdd seg[N];
int n,segcnt;
DB r;
DB angel(point a)   {return atan2(a.y,a.x);}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x>0?1:-1;
}
void add(point a,point b)
{
    DB mi=angel(a),ma=angel(b);
    if(mi<0)    mi+=2*pi;
    if(ma<0)    ma+=2*pi;
    if(dcmp(mi-ma)==0)  return;
    if(mi>ma)   swap(mi,ma);
    if(ma-mi<=pi)
        seg[segcnt++] = pdd(mi,ma);
    else
    {
        seg[segcnt++] = pdd(0.0,mi);
        seg[segcnt++] = pdd(ma,2*pi);
    }
}

void run()
{
    scanf("%d%lf",&n,&r);
    segcnt = 0;
    point a,b;
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        add(a,b);
    }
    sort(seg,seg+segcnt);
    DB ans = 0.0,l=-1000000.0;
    for(int i=0;i<segcnt;++i)
    {
        if(seg[i].x > l)
            l = seg[i].x;
        if(seg[i].y > l)
        {
            ans += seg[i].y - l;
            l = seg[i].y;
        }
    }
    static int cas = 1;
    printf("Case %d: %.2lf%%\n",cas++,100.0-100.0*ans/(2*pi));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
