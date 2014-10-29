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
    return (r-m)*(m-l)>=0;
}

int main()
{
    //freopen("case.txt","r",stdin);
    int T;
    xy s,e,a,t;
    double k1,k2;
    cin>>T;
    while(T--)
    {
        cin>>s.x>>s.y>>e.x>>e.y>>a.x>>a.y;//change when submit*********
        if(s.x==e.x)
        {
            if(between(a.y,s.y,e.y))
                PYES
            else
                PNO
        }
        if(!between(a.x,s.x,e.x))
            PNO
        if(s.x>e.x){t=s;s=e;e=t;}
        if(a.x==s.x&&a.y==s.y)
            PYES
        k1=(e.y-s.y)/(e.x-s.x);
        k2=(a.y-s.y)/(a.x-s.x);
        if(k1==k2)
            PYES
        else
            PNO
    }
    return 0;
}
