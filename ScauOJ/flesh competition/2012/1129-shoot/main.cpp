#include <iostream>
#include <cstdio>
#define PYES {cout<<"YES"<<endl;continue;}
#define PNO {cout<<"NO"<<endl;continue;}

using namespace std;

struct xy{
    double x,y;
};

inline bool between(double m,double l,double r)
{
    return (r-m)*(m-l)>0;
}

int main()
{
    freopen("case.txt","r",stdin);
    int T;
    xy s,e,a;
    double k1,k2;
    cin>>T;
    while(T--)
    {
        cin>>s.x>>s.y>>e.x>>e.y>>a.x>>a.y;//change when submit*********
        if((s.x==e.x&&a.x==s.x)||(s.y==e.y&&a.y==s.y))
            PYES
        if((a.x==s.x&&a.y==s.y)||(a.x==e.x&&a.y==e.y))//output YES if a is same place in s or e
            PYES
        if((a.x==s.x||a.x==e.x)||(a.y==s.y||a.y==e.y))
            PNO
        if(!(between(a.x,s.x,e.x)&&between(a.y,s.y,e.y)))//output NO if isn't between
            PNO
        k1=(e.y-a.y)/(e.x-a.x);
        k2=(a.y-s.y)/(a.x-s.x);
        if(k1==k2)PYES
        else PNO
    }
    return 0;
}
