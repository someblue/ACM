#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;

inline int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

struct line {
    double l,r,y;
    line() {}
};

int n;
line hou,pro;
vector<line> obj;
vector<pair<double,int> > res;

double getx(double x1,double y1,double x2,double y2,double y)
{
    if(dcmp(x1-x2)==0)  return x1;
    return x2+(x2-x1)/(y1-y2)*(y2-y);
}

void run()
{
    scanf("%lf%lf%lf",&pro.l,&pro.r,&pro.y);
    scanf("%d",&n);
    obj.clear();
    res.clear();
    line t;
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf%lf",&t.l,&t.r,&t.y);
        if(t.y >= hou.y || t.y < pro.y) continue;
        obj.push_back(t);
    }
    n = obj.size();
    double x;
    for(int i=0;i<n;++i)
    {
        x = getx(hou.r,hou.y,obj[i].l,obj[i].y,pro.y);
        res.push_back(make_pair(x,1));
        x = getx(hou.l,hou.y,obj[i].r,obj[i].y,pro.y);
        res.push_back(make_pair(x,-1));
    }
    res.push_back(make_pair(pro.l,0));
    res.push_back(make_pair(pro.r,0));
    sort(res.begin(),res.end());
    double ans = -1.0, temp;
    double l=pro.l, r=pro.r;
    int cnt=0,len=res.size();
    for(int i=0;i<len;++i)
    {
        if(dcmp(res[i].first-r)>=0)   break;
        cnt+=res[i].second;
        if(cnt==0)
        {
            if(dcmp(res[i].first-l)<0)    continue;
            temp = res[i+1].first - res[i].first;
            if(dcmp(temp-ans)>0)
                ans = temp;
        }
    }
    if(dcmp(ans)<=0)    printf("No View\n"); //puts("No View");
    else    printf("%.2lf\n",ans);
}

void text()
{
    double x1,y1,x2,y2,y;
    while(cin>>x1>>y1>>x2>>y2>>y)
        cout<<getx(x1,y1,x2,y2,y)<<endl;
}

int main()
{
    freopen("case.txt","r",stdin);
//    text();
    while(scanf("%lf%lf%lf",&hou.l,&hou.r,&hou.y)!=EOF)
    {
        if(dcmp(hou.l)==0 && dcmp(hou.r)==0 && dcmp(hou.y)==0)  break;
        run();
    }
    return 0;
}
