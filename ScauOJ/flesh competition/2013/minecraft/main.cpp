#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    const double g=10,pi=3.141592654;
    double s,a,v,t,r,vx,vy,tm,x,y;
    scanf("%lf%lf%lf%lf%lf",&s,&a,&v,&t,&r);
    a*=pi/180;vx=v*cos(a);vy=v*sin(a);
    tm=2*vy/10;
    if(tm<=t)
    {
        y=0;
        x=vx*tm;
    }
    else
    {
        x=vx*t;
        y=vy*t-g/2*t*t;
    }
    if(pow(abs(x-s),2.0)+pow(y,2.0)<=pow(r,2.0))
        printf("nice!");
    else
        printf("T^T");
    return 0;
}
