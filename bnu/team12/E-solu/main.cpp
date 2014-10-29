#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;


#define eps 1e-8

const double pi=acos(-1.0);

struct point
{
    double x,y;
    double angle;
    double w;
    int d;
    point(double xx,double yy){x=xx;y=yy;}
    point(){x=0.0;y=0.0;}

    point(double xx,double yy,double aa,int dd){x=xx;y=yy;angle=aa;d=dd;}

    point operator-(const point &p)
    {
        return point(x-p.x,y-p.y);
    }

    point operator+(const point &p)
    {
        return point(x+p.x,y+p.y);
    }

    point operator*(const double &d)
    {
        return point(x*d,y*d);
    }
    point operator/(const double &d){
        return point(x/d,y/d);
    }

};

point p[12311];
point q[12311];
point u;
bool ok[12311];

double len(point a){
    return sqrt(a.x*a.x+a.y*a.y);
}

int n;
double rr;

double dis(point p1,point p2){
    return len(p1-p2);
}

double sig(double x){
    return (x>eps)-(x<-eps);
}

double cross(point p1,point p2){
    return p1.x*p2.y-p2.x*p1.y;
}

point intersection(point u1,point u2,point v1,point v2){
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
    ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));


    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}


void intersection_line_circle(point test,point c,double r,point l1,point l2,point& p1,point& p2){
    point p=c;
    double t;

    p.x+=l1.y-l2.y;
    p.y+=l2.x-l1.x;
    p=intersection(p,c,l1,l2);
    t=sqrt(r*r-dis(p,c)*dis(p,c))/dis(l1,l2);

    p1.x=p.x+(l2.x-l1.x)*t;
    p1.y=p.y+(l2.y-l1.y)*t;
    p2.x=p.x-(l2.x-l1.x)*t;
    p2.y=p.y-(l2.y-l1.y)*t;

    if( sig(cross(p2-p1,test-p1))>0 )
        swap(p1,p2);
}

point getpvec(point p1,point p2){
    point ret=p2-p1;
    swap(ret.x,ret.y);
    ret.x*=-1.0;
    return ret;
}

bool cmp(const point& u, const point& v) {
    if (sig(u.angle - v.angle)) return u.angle < v.angle;
    return u.d > v.d;
}

bool check(int now,point &ret){

    point st,ed;
    point tp[11111];

    int tn=0,cnt=0;


    point inter1,inter2;
    point o=point(0,0);
    for(int i=1;i<=n;i++)
    if(now!=i){

        point u=(p[now]+p[i])*0.5;
        point v=getpvec(p[now],p[i]);
        v=u+v;
        intersection_line_circle(p[now],o,rr,u,v,inter1,inter2);

        inter1.angle = atan2(inter1.y,inter1.x);
        inter2.angle = atan2(inter2.y,inter2.x);
        inter1.d=1;     tp[tn++]=inter1;
        inter2.d=-1;    tp[tn++]=inter2;
        if(sig(inter1.angle-inter2.angle)>0)cnt++;

    }
    tp[tn++]=point(-rr,0, pi,-cnt);
    tp[tn++]=point(-rr,0,-pi, cnt);

    sort(tp,tp+tn,cmp);

    int s=tp[0].d;

    for(int i=1;i<tn;i++){
        s+=tp[i].d;
        if(s>=n-1)
        {
            ret.x=cos(tp[i].angle)*rr;
            ret.y=sin(tp[i].angle)*rr;
            return true;
        }
    }
    return false;
}

double dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}

int main()
{
    cin>>rr;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y>>p[i].w;


    double maxd=-11111;
    point ans,ret;

    for(int i=1;i<=n;i++)
    if(check(i,ret) && p[i].w>maxd){
        ans=ret;
        maxd=p[i].w;
    }
    printf("%.10f %.10f",ans.x,ans.y);



    return 0;
}
