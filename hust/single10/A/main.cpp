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
    if(dcmp(mi-ma)==0)  return;
    if(mi>ma)   swap(mi,ma);
    mi = mi*180.0/pi;
    ma = ma*180.0/pi;
//    cout<<mi<<' '<<ma<<endl;
//    if(ma-mi<=pi)
    if(dcmp(ma-mi-180.0)<=0)
        seg[segcnt++] = pdd(mi,ma);
    else
    {
        seg[segcnt++] = pdd(-180.0,mi);
        seg[segcnt++] = pdd(ma,180.0);
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
//    cout<<"cnt:"<<segcnt<<endl;
    DB ans = 0.0,l=-1000000.0;
    for(int i=0;i<segcnt;++i)
    {
//        cout<<seg[i].x<<' '<<seg[i].y<<endl;
//        if(seg[i].x > l)
        if(dcmp(seg[i].x-l)>0)
            l = seg[i].x;
//        if(seg[i].y > l)
        if(dcmp(seg[i].y-l)>0)
        {
            ans += seg[i].y - l;
            l = seg[i].y;
        }
    }
//    cout<<"ans:"<<ans<<endl;
    static int cas = 1;
//    printf("Case %d: %.2lf%%\n",cas++,100.0-100.0*ans/(2*pi));
    printf("Case %d: %.2lf%%\n",cas++,100.0-ans/3.6);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
