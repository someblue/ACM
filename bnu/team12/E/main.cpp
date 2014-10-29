#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#define REP(i,n) for(i=0;i<(n);i++)
#define FOR(i,n) for(i=1;i<=(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-10;
const int N = 1010;
int cas = 1;
//  http://vjudge.net/vjudge/contest/view.action?cid=54915#overview
//  http://www.bnuoj.com/bnuoj/contest_show.php?cid=4707

typedef pair<double ,int > pdi;
const double PI = acos(-1.0);

inline int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}


struct point {
    double x,y;
    int w;
    bool operator < (const point &b) const {
        return w > b.w;
    }
};

point p[N];
int n;
double R;
vector<pdi> event[N];

void get_inter(int i,int j)
{
    point a,b;
    a=p[i];
    b=p[j];
    double x1,x2,y1,y2;
    if(dcmp(a.y-b.y)==0)
    {
        x1 = x2 = (a.x+b.x)/2;
        y1 = sqrt(R*R-x1*x1);
        y2 = -sqrt(R*R-x2*x2);

    }
    else if(dcmp(a.x-b.x)==0)
    {
        y1 = y2 = (a.y+b.y)/2;
        x1 = sqrt(R*R-y1*y1);
        x2 = -sqrt(R*R-y2*y2);
    }
    else
    {
        double k = -(a.x-b.x)/(a.y-b.y);
        double bb = (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)/(2*(a.y-b.y));
        double A = k*k+1;
        double B = 2*k*bb;
        double C = bb*bb-R*R;
        double delta = B*B-4*A*C;
         x1 = (-B+sqrt(delta))/(2*A);
         x2 = (-B-sqrt(delta))/(2*A);
         y1 = k*x1+bb;
         y2 = k*x2+bb;
//         y1 = sqrt(R*R-x1*x1);
//         y2 = sqrt(R*R-x2*x2);
    }
//    printf("(%lf,%lf) (%lf,%lf)\n",x1,y1,x2,y2);

    double l,r;
    l = atan2(y1,x1);
    r = atan2(y2,x2);
    if(l>r) swap(l,r);

    if(dcmp(l+PI)==0 || dcmp(r-PI)==0)
    {
        if(dcmp(l+PI)==0)
        {
            if(p[i].y>p[j].y)
            {
                swap(i,j);
            }
            event[i].push_back(make_pair(-PI,1));
            event[i].push_back(make_pair(r,-1));
            event[j].push_back(make_pair(r,1));
            event[j].push_back(make_pair(PI,-1));
        }
        else if(dcmp(r-PI)==0)
        {
            if(p[i].y>p[j].y)
            {
                swap(i,j);
            }
            event[i].push_back(make_pair(-PI,1));
            event[i].push_back(make_pair(l,-1));
            event[j].push_back(make_pair(l,1));
            event[j].push_back(make_pair(PI,-1));
        }
        return;
    }
    event[j].push_back(make_pair(l,1));
    event[j].push_back(make_pair(r,-1));
    event[i].push_back(make_pair(-PI,1));
    event[i].push_back(make_pair(l,-1));
    event[i].push_back(make_pair(r,1));
    event[i].push_back(make_pair(PI,-1));
}

double ansx,ansy;
bool judge(int i)
{
    int cnt = 0;
    sort(event[i].begin(),event[i].end());
    int sz = event[i].size();
    for(int j=0;j<sz;j++)
    {
        cnt += event[i][j].second;
        if(cnt >= n-1)
        {
            double tmp = event[i][j].first;
            ansx = R*cos(tmp);
            ansy = R*sin(tmp);
            return 1;
        }
    }
    return 0;
}

void run()
{
    for(int i=1;i<=n;i++)   event[i].clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].w);
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(p[i].x < p[j].x)
                get_inter(i,j);
            else
                get_inter(j,i);
        }
        if(judge(i))
        {
            break;
        }
    }
//    cout<<flag<<endl;
    printf("%.10lf %.10lf\n",ansx,ansy);
}

int main()
{
    #ifdef LOCAL
    freopen("in","r",stdin);
    #endif
    while(scanf("%lf%d",&R,&n)!=EOF)
        run();
    return 0;
}
