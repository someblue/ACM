#include <iostream>
#include <cstdio>

using namespace std;

double mod(double a,double mod)
{
    double b = a;
    while(b>=0) b -= mod;
    //b += mod;
    return b+mod;
}

int main()
{
    double l,d,v,g,r,t_wait,t_light,t_pass;
    cin>>l>>d>>v>>g>>r;
    t_pass = l/v;
    //t_light = d/v % mod;
    t_light = mod(d/v,g+r);
    t_wait = t_light<g ? 0:(g+r - t_light);
    printf("%.8lf\n",t_pass + t_wait);
    return 0;
}
