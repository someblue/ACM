#include <iostream>
#include <cstdio>

using namespace std;

struct _xy{
    double x,y;
};

void cnt_abc(_xy xy1,_xy xy2,double &a,double &b,double &c)
{
    if(xy1.x==xy2.x)
    {
        a=1;b=0;c=-xy1.x;
        return;
    }
    a=(xy2.y-xy1.y)/(xy2.x-xy1.x);
    b=-1;
    c=xy1.y-a*xy1.x;
}

bool inters(double a,double b,double c,double d)
{
    return ((c-a)*(c-b)<=0) || ((d-a)*(d-b)<=0);
}

bool twoside(_xy xy1,_xy xy2,double a,double b,double c,_xy xy3,_xy xy4)
{
//    printf("x1:%lf,y1:%lf\n",xy1.x,xy1.y);
//    printf("x2:%lf,y2:%lf\n",xy2.x,xy2.y);
//    printf("a*x1+b*y1+c:%lf\n",a*xy1.x+b*xy1.y+c);
//    printf("a*x2+b*y2+c:%lf\n",a*xy2.x+b*xy2.y+c);
    double ans1,ans2;
    ans1=a*xy1.x+b*xy1.y+c;
    ans2=a*xy2.x+b*xy2.y+c;
    if(ans1*ans2<=0)
    {
        if(ans1-ans2!=0) return 1;
        else if(inters(xy1.x,xy2.x,xy3.x,xy4.x)&&inters(xy1.y,xy2.y,xy3.y,xy4.y))
            return 1;
    }
    return 0;
//    return (a*xy1.x+b*xy1.y+c)*(a*xy2.x+b*xy2.y+c)<=0;
}

int main()
{
    int T,i;
    double a1,a2,b1,b2,c1,c2;
    _xy xy[4];
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<4;i++)
            scanf("%lf%lf",&xy[i].x,&xy[i].y);
        cnt_abc(xy[0],xy[1],a1,b1,c1);
        cnt_abc(xy[2],xy[3],a2,b2,c2);
//        printf("a1:%lf,b1:%lf,c1:%lf\n",a1,b1,c1);
//        printf("a2:%lf,b2:%lf,c2:%lf\n",a2,b2,c2);
        if(twoside(xy[2],xy[3],a1,b1,c1,xy[0],xy[1]) && twoside(xy[0],xy[1],a2,b2,c2,xy[2],xy[3]))
            printf("y\n");
        else
            printf("n\n");
    }
    return 0;
}
