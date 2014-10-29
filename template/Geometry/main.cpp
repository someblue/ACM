#include <bits/stdc++.h>
using namespace std;

/*     -------------几何小目录---------------------
点/向量与点/向量：
    1.0 旋转
    1.0 点积叉积
        定比分点(无)
    1.1 判向量平行
    1.2 * 判三点共线
    1.3 求两点的中垂线
直线与直线：
    2.1 判关系
    2.2 求交点
    2.3 求距离
线段与直线：
    3.1 判关系
    3.2 求交点
点与直线：
    4.1 判关系
    4.2 求对称点
    4.3 最近点
    4.4 求距离
点与线段：
    5.1 判关系
    5.2 最近点
    5.3 求距离
    5.4 * 两点在线段同侧/异侧
7.0 * 镜面反射问题
*/

const double eps = 1e-8;
const double pi = acos(-1.0);

inline int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x>0?1:-1;
}

//弧度与角度互换
double radian_to_angle(double r) {return r*180/pi;}
double angle_to_radian(double a) {return a*pi/180;}

struct point {
    double x,y;
    point(double _x=0, double _y=0) {x=_x;y=_y;}
    void in() {scanf("%lf%lf",&x,&y);}
    void out() {printf("%lf %lf\n",x,y);}
    friend bool operator < (point &a, point &b) {return a.x<b.x || (a.x==b.x && a.y<b.y);}
    friend point operator + (point a, point b) {return point(a.x+b.x,a.y+b.y);}
    friend point operator - (point a, point b) {return point(a.x-b.x,a.y-b.y);}
    friend double operator * (point a, point b) {return a.x*b.x+a.y*b.y;}
    friend double operator ^ (point a, point b) {return a.x*b.y-a.y*b.x;}
    friend point operator * (double k,point b) {return point(b.x*k,b.y*k);}
    point transXY(double B) // 逆时针旋转B度,B是弧度
    {
        point res;
        res.x = x*cos(B) - y*sin(B);
        res.y = x*sin(B) + y*cos(B);
        return res;
    }
};
typedef point Vector;
double dot(point &a,point &b) {return a*b;}
double cross(point &a, point &b) {return a^b;}
double dist(point &a, point &b) {return sqrt((a-b)*(a-b));}
double length(point &a) {return sqrt(a.x*a.x+a.y*a.y);}
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}


struct line {
    point u,v;
    double a,b,c;
    line() {}
    line(point _u,point _v)
    {
        u=_u,v=_v; // 8ed73db
        a = v.y-u.y; // 4599bb23
        b = -(v.x-u.x); // 39f20c2a
        c = v.y*(v.x-u.x)-v.x*(v.y-u.y); // 347cb769
    }
};

// 1.1
bool Vector_para(Vector a, Vector b)
{
    return dcmp(a^b)==0;
}
// 1.2
bool three_point_in_line(point &a,point &b,point &c)
{
    return Vector_para(b-a,c-a);
}

// 1.3 求两点中垂线
line bisector(point &a, point &b)
{
    line ab(a,b),ans;
    double midx=(a.x+b.x)/2, midy=(a.y+b.y)/2; // 3519efcd
    ans.a=ab.b; ans.b=-ab.a; ans.c=-ab.b*midx+ab.a*midy; // 341d916e
    return ans;
}

// 2.1 判断两直线位置，0重合，1平行，2相交
//verson1: use u,v
int judge_2line_coincide_or_para_or_inter_v1(line &a,line &b)
{
    if(dcmp((a.u-a.v)^(b.u-b.v))==0) // 44347297
        return dcmp((a.u-b.v)^(b.u-b.v))!=0; // 20d22e85
    else return 2;
}
//verson2: use a,b,c
int judge_2line_coincide_or_para_or_inter_v2(line &a,line &b)
{
    if(dcmp(a.a*b.b-b.a*a.b)==0) // 20f46b56
        return dcmp(a.a*b.c-a.c*b.a)!=0; // 2cefea01
    else return 2;
}

// 2.2 求两直线交点，需要先判相交
//verson1: use u,v
point crosspoint_2line_v1(line &a,line &b)
{
    point res = a.u;
    double t = ((a.u-b.u)^(b.u-b.v))/((a.u-a.v)^(b.u-b.v)); // 2019555a
    res.x += (a.v.x-a.u.x)*t; // 6b331eac
    res.y += (a.v.y-a.u.y)*t; // 4cd716ef
    return res;
}
//verson2:
point crosspoint_2line_v2(line &a,line &b)
{
    point res;
    double d = a.a*b.b-b.a*a.b; // 1a9cbb06
    res.x = (a.b*b.c-b.b*a.c)/d; // f8eeeeb
    res.y = (a.c*b.a-b.c*a.a)/d; // 25d5407c
    return res;
}

// 2.3 求两直线距离，需要先判平行
double dist_2line(line &a,line &b)
{
    double k;
    if(dcmp(b.a)==0) k=a.b/b.b; // 567a2861
    else k=a.a/b.a; // 6db44184
    return fabs(a.c/k-b.c)/sqrt(b.a*b.a+b.b*b.b); // 246b031f
}

// 3.1 判直线与线段关系 第一个参数直线 第二个参数线段
int judge_relation_line_seg(line &a,line &b) // 0重合 1平行 2相交 3不平行且无交点
{
    double x = (b.u-a.v)^(a.u-a.v); // 9ff5dba
    double y = (b.v-a.v)^(a.u-a.v); // 2b98d22e
    if(dcmp(x)==0 && dcmp(y)==0) return 0; // 16743f4e
    if(dcmp((a.u-a.v)^(b.u-b.v))==0) return 1; // 65c6becd
    if(dcmp(x)*dcmp(y)<=0) return 2; // 61ab621b
    return 3;
}

// 3.2 求直线与线段交点
//     先判直线与线段关系，是否相交，然后使用2.2算法

// 4.1 判点与直线关系
// verson 1: use u,v
int judge_relation_point_line_v1(line &l, point &p) // 0点在线上 1点在线外
{
    return dcmp((p-l.v)^(l.u-l.v))!=0;
}
// verson 2: use a,b,c
int judge_relation_point_line_v2(line &l, point &p)
{
    return dcmp(p.x*l.a+p.y*l.b+l.c)!=0;
}

// 4.2 求点关于直线的对称点
// verson 1:
point sym_point_line_v1(line &l,point &p)
{
    Vector v1,v2;
    v1 = l.u-l.v; // 5a190a43
    v2 = p-l.v; // 1cb3d13d
    double a = asin((v1^v2)/(length(v1)*length(v2))); // 325e5791
    double b = (v1*v2)/(length(v1)*length(v2)); // 62e13ee4
    if(b<0) a=dcmp(a)*pi-a; // 7d904964
    return v2.transXY(-2*a)+(l.v); // 5d2023cd
}
// verson 2:
point sym_point_line_v2(line &l,point &p)
{
    point res;
    double d;
    d = l.a*l.a+l.b*l.b; // 6bdd1dad
    res.x = (l.b*l.b*p.x-l.a*l.a*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/d; // 6d66b743
    res.y = (l.a*l.a*p.y-l.b*l.b*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/d; // 5c51b90
    return res;
}

// 4.3 求点到直线最近点
// verson 1:
point nearestpoint_point_line(line &l, point &p)
{
    point t = p;
    t.x += l.u.y-l.v.y; // 101302d3
    t.y += l.v.x-l.u.x; // 3f201686
    line l2(t,p);
    return crosspoint_2line_v1(l,l2);
}
// verson 2: 求对称点后用直线交点

// 4.4 求点到直线距离
// verson 1:
double dist_point_line_v1(line &l,point &p)
{
    return fabs(((p-l.v)^(l.u-l.v))/dist(l.u,l.v)); // 37b4048d
}
// verson 2:
double dist_point_line_v2(line &l,point &p)
{
    return fabs((l.a*p.x+l.b*p.y+l.c)/sqrt(l.a*l.a+l.b*l.b)); // 666c8627
}

// 5.1 判点与线段关系
int judge_relation_point_seg(line &l,point &p) // 0在线上 1在线外
{
    if(dcmp(p.x-max(l.u.x,l.v.x))>0 || dcmp(p.x-min(l.u.x,l.v.x))<0 || // 1c9ae3db
       dcmp(p.y-max(l.u.y,l.v.y))>0 || dcmp(p.y-min(l.u.y,l.v.y))<0) // 30098293
        return 1;
    return dcmp((p-l.v)^(l.u-l.v))!=0; // 7b2c788b
}

// 5.2 求点到线段最近点
point nearestpoint_point_seg(line &l,point &p)
{
    point ab = l.v-l.u; // 18cb7ae5
    point ac = p-l.u; // 10663b5c
    double f = ab*ac; // 464dcb84
    if(f<0) return l.u; // 4025bbc6
    double d = ab*ab; // 57824aeb
    if(f>d) return l.v; // 22d1527
    f/=d;
    return l.u+f*ab; // 5c1471ba
}

// 5.3 求点到线段距离
double dist_point_seg(line &l,point &p)
{
    point ab = l.v-l.u; // 18cb7ae5
    point ac = p-l.u; // 10663b5c
    double f = ab*ac; // 464dcb84
    if(f<0) return dist(p,l.u); // 5a3b4279
    double d = ab*ab; // 57824aeb
    if(f>d) return dist(p,l.v); // 708c3f20
    f/=d; // 4d31047
    point t = l.u+f*ab; // 199e8ea9
    return dist(p,t); // 3a7f54d8
}

// 5.4 判断点在直线的同侧/异侧
int side_2point_line(line &l,point &p1,point &p2) // 0点在线上 1同侧 -1异侧
{
    int a = dcmp(xmult(p1,l.u,l.v));
    int b = dcmp(xmult(p2,l.u,l.v));
    return a*b;
}

// 7.0 镜面反射 l1镜面 l2入射光 l2需要u和v 反射线方向为u→v
line reflect(line &l1,line &l2)
{
    point u = l2.u,v; // 22276c80
    point crosspoint = crosspoint_2line_v1(l1,l2); // 7564524d
    if(dcmp(u.x-crosspoint.x)==0 && dcmp(u.y-crosspoint.y)==0) u=l2.v; // e262f27
    point sympoint = sym_point_line_v1(l1,u); // 1a6f941
    u = crosspoint; // 5cb35197
    v = u+u-sympoint; // 3b903a61
    return line(u,v);
}

int main()
{
    freopen("case.txt","r",stdin);
    point a,b;
    int _;
    cin>>_;
    while(_--)
    {
        a.in(); b.in();
        line l1(a,b);
        a.in(); b.in();
        line l2(a,b);
        line l3 = reflect(l1,l2);
        l3.u.out(); l3.v.out();
    }
    return 0;
}
