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
#include <list>
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 5005;

typedef double DB;
typedef pair<DB,DB> point;
#define x first
#define y second
point operator - (const point &a, const point &b)   {return make_pair(a.x-b.x,a.y-b.y);}
DB cross(const point &a, const point &b)    {return a.x*b.y - b.x*a.y;}

int sgn(DB x)
{
    if(fabs(x)<eps) return 0;
    return x<0? -1 : 1;
}

struct _line {
    DB upx,downx,maxx,minn;
    void update()
    {
        maxx = max(upx,downx);
        minn = min(upx,downx);
    }
    friend bool operator < (const _line &a, const _line &b)
    {
        return a.downx < b.downx;
    }
};

DB x1,x2,yy1,y2;
int n,m;
_line l[N];
point p[N];
int cnt[N];

bool fir=1;

void run()
{
    int i;
    for(i=1;i<=n;++i)
    {
        scanf("%lf%lf",&l[i].upx,&l[i].downx);
        l[i].update();
    }
    sort(l+1,l+n+1);
    l[n+1].upx = l[n+1].downx = x2;
    l[n+1].update();
    for(i=1;i<=m;++i)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p+1,p+m+1);
    memset(cnt,0,sizeof(cnt));
    list<int> q;
    list<int>::iterator it;
    int ptr=1;
    point pl,pd;
    for(i=1;i<=n+1 && ptr<=m;++i)
    {
        pd = make_pair(l[i].downx,y2);
        pl = make_pair(l[i].upx,yy1) - pd;
        while(ptr<=m)
        {
            if(!q.empty())
            {
                for(it = q.begin();it!=q.end();)
                {
                    if(sgn(p[*it].x - l[i].minn)<=0)    ++cnt[i],it=q.erase(it);
                    else if(sgn(p[*it].x - l[i].maxx)>=0)   it++;
                    else if(sgn(cross(p[*it]-pd,pl))<=0)    ++cnt[i],it=q.erase(it);
                    else it++;
                }
            }
            if(sgn(p[ptr].x - l[i].minn)<=0)    {++cnt[i],++ptr;continue;}
            else if(sgn(p[ptr].x - l[i].maxx)>=0)    break;
            else if(sgn(cross(p[ptr]-pd,pl))<=0)    ++cnt[i],++ptr;
            else q.push_back(ptr),++ptr;
        }
    }
    if(fir) fir=0;
    else puts("");
    for(i=0;i<=n;++i)
        printf("%d: %d\n",i,cnt[i+1]);
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d%lf%lf%lf%lf",&n,&m,&x1,&yy1,&x2,&y2)!=EOF && n)
        run();
    return 0;
}
