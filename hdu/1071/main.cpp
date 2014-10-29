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
typedef pair<double,double> point;
#define x first
#define y second

point p1,p2,p3;
double a,b,k;

double f(double xx)
{
    return a*xx*xx*xx/3-a*p1.x*xx*xx+a*p1.x*p1.x*xx+p1.y*xx-k*xx*xx/2-b*xx;
//    return 2*(xx-a)-kk;
}

void run()
{
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
    a=(p2.y-p1.y)/((p2.x-p1.x)*(p2.x-p1.x));
    k=(p3.y-p2.y)/(p3.x-p2.x);
    b=p2.y-k*p2.x;
//    cout<<a<<' '<<b<<' '<<c<<endl;
    printf("%.2lf\n",f(p3.x)-f(p2.x));
}

int main()
{
    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
