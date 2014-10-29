#include <iostream>

using namespace std;

int main()
{
    double x1,y1,r1,x2,y2,r2,d;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if(d<=(r1+r2)*(r1+r2)&&d>=(r2-r1)*(r2-r1))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
