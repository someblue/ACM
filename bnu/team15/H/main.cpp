#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-8;
const int N = 1000;
const double PI = acos(-1.0);
int cas = 1;

//  http://www.bnuoj.com/bnuoj/contest_show.php?cid=4746

int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
bool zero(double x)
{
    return fabs(x)<eps;
}

struct point {
    double x,y;
    point(){}
    point (double _x,double _y)
    {
        x=_x; y=_y;
    }
    point operator - (const point &b) const
    {
        return point(x-b.x,y-b.y);
    }
    double operator ^ (const point &b) const
    {
        return x*b.y - y*b.x;
    }
    double lenth()
    {
        return sqrt(x*x+y*y);
    }
    double operator * (const point &b) const
    {
        return x*b.x+y*b.y;
    }
    point operator + (const point &b) const
    {
        return point(x+b.x,y+b.y);
    }
};

struct line {
    point s,e;
    double a,b,c;
    line() {}
    line(point _s,point _e)
    {
        s = _s; e = _e;
        a = s.y - e.y;
        b = e.x - s.x;
        c = s.x*e.y - s.y*e.x;
    }
};

double r,s;
int speed;
point hexx[10];
point p1,p2;
line ln[10];

point point_to_line(point p,line l)// ok
{
    point result;
    double t = ((p-l.s)*(l.e-l.s))/((l.e-l.s)*(l.e-l.s));
    result.x = l.s.x + (l.e.x-l.s.x)*t;
    result.y = l.s.y + (l.e.y-l.s.y)*t;
    return result;
}

double dist(point a,point b) // ok
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool judge(line l)// ok
{
    point t = point_to_line(point(0,0),l);
//    cout<<t.x<<' '<<t.y<<endl;

    double t1 = atan2(l.e.y-l.s.y,l.e.x-l.s.x);
    double t2 = atan2(t.y-l.s.y,t.x-l.s.x);
    if(dcmp(t1+PI)==0) t1+=PI;
    if(dcmp(t2+PI)==0) t2+=PI;
    if(dcmp(t1-t2)!=0) return 0;

    return t.lenth()<=r+1e-6;
}

point intersection(line u,line v) // ok
{
    point ret = u.s;
    double t = ((u.s.x-v.s.x)*(v.s.y-v.e.y)-(u.s.y-v.s.y)*(v.s.x-v.e.x))
            / ((u.s.x-u.e.x)*(v.s.y-v.e.y)-(u.s.y-u.e.y)*(v.s.x-v.e.x));
    ret.x+=(u.e.x-u.s.x)*t;
    ret.y+=(u.e.y-u.s.y)*t;
    return ret;
}

bool parrallel(line u,line v) // ok
{
    return zero((u.s.x-u.e.x)*(v.s.y-v.e.y)-(v.s.x-v.e.x)*(u.s.y-u.e.y));
}

point get_point_line(point p1,point p2,int &k) // ok
{
    line l(p1,p2);
    point ret,tmp;
    double mn=1e10;
    k = -1;
    for(int i=0;i<6;i++)
    {
        if(parrallel(l,ln[i]))  continue;
        tmp = intersection(l,ln[i]);
        double t1 = atan2(p2.y-p1.y,p2.x-p1.x);
        double t2 = atan2(tmp.y-p1.y,tmp.x-p1.x);
        if(dcmp(t1+PI)==0) t1+=PI;
        if(dcmp(t2+PI)==0) t2+=PI;
        if(dcmp(t1-t2)!=0) continue;
        double dis = dist(p1,tmp);
        if(dis<mn)
        {
            mn = dis;
            ret = tmp;
            k = i;
        }
    }
    return ret;
}

bool point_in_coner(point p) // ok
{
    for(int i=0;i<6;i++)
    {
        if(dcmp(p.x-hexx[i].x)==0 && dcmp(p.y-hexx[i].y)==0)
            return 1;
    }
    return 0;
}

point sym(point p,line l)  // ok
{
    point p2;
    double d;
    d = l.a*l.a + l.b*l.b;
    p2.x = (l.b*l.b*p.x-l.a*l.a*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/d;
    p2.y = (l.a*l.a*p.y-l.b*l.b*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/d;
    return p2;
}


void run()
{
    scanf("%lf%lf%lf%lf%lf%lf%d",&s,&p1.x,&p1.y,&p2.x,&p2.y,&r,&speed);
    printf("Case %d: ",cas++);
    if(p1.lenth()<=r+1e-6)
    {
        printf("%d\n",speed);
        return;
    }
    double three = sqrt(3.0)/2*s;
    hexx[0] = point(-s,0);
    hexx[1] = point(-s/2,-three);
    hexx[2] = point(s/2,-three);
    hexx[3] = point(s,0);
    hexx[4] = point(s/2,three);
    hexx[5] = point(-s/2,three);
    for(int i=0;i<6;i++)
        ln[i] = line(hexx[i],hexx[(i+1)%6]);
//    for(int i=0;i<6;i++)
//    {
//        cout<<hexx[i].x<<' '<<hexx[i].y<<endl;
//    }
    while(speed>0)
    {
        line l(p1,p2);
//        cout<<p1.x<<' '<<p1.y<<' '<<p2.x<< ' '<<p2.y<<' '<<r<<endl;
        if(judge(l))
        {
            printf("%d\n",speed);
            return;
        }
        int k;
        point p3 = get_point_line(p1,p2,k);
//        cout<<p3.x<<' '<<p3.y<<endl;
        if(point_in_coner(p3))
        {
            speed -= 2;
//            swap(p1,p3);
            p2 = p1;
            p1 = p3;
        }
        else
        {
            speed--;
            point p4 = sym(p1,ln[k]);
            point dp = p3-p4;
            p4=p4+dp;
            p3=p3+dp;
            p1 = p4;
            p2 = p3;
        }
//        cout<<p1.x<<' '<<p1.y<<endl;
    }
    printf("Stops\n");
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}

