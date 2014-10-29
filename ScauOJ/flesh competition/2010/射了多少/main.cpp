#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct xy{
    double x,y;
};

bool isinit(double k)
{
    double f;
    f=floor(k+0.5);
    if((k-f)<0.0001&&(k-f)>-0.0001) return 1;
    return 0;
}

int main()
{
    xy left,right,temp;
    cin>>left.x>>left.y>>right.x>>right.y;
    if(left.x==right.x||left.y==right.y){cout<<'0'<<endl;return 0;}
    if(left.x>right.x){temp=right;right=left;left=temp;}
    double i,k,sum=0,high,low;
    xy l,r;
    k=(right.y-left.y)/(right.x-left.x);
    for(i=left.x;i<right.x;i++)
    {
        l.x=i;r.x=i+1;
        l.y=k*(l.x-left.x)+left.y;
        r.y=k*(r.x-left.x)+left.y;
        if(isinit(l.y))l.y=floor(l.y+0.5);
        if(isinit(r.y))r.y=floor(r.y+0.5);
        if(l.y<r.y)
        {
            high=ceil(r.y);
            low=floor(l.y);
        }
        else
        {
            high=ceil(l.y);
            low=floor(r.y);
        }
        sum+=high-low;
    }
    printf("%.0f\n",sum);
//    double num;
//    while(cin>>num,num!=-1)
//    {
//        if(isinit(num))cout<<"yes"<<endl;
//        else cout<<"no"<<endl;
//    }
    return 0;
}
