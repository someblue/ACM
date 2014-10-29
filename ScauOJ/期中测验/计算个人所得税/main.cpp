#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double in,ans=0;
    cin>>in;
    if(in<=1600)
        ans=0;
    else if(in<=3000)
        ans=(in-1600)*0.1;
    else if(in<=4200)
        ans=(3000-1600)*0.1+(in-3000)*0.15;
    else if(in<=10000)
        ans=(3000-1600)*0.1+(4200-3000)*0.15+(in-4200)*0.2;
    else
        ans=(3000-1600)*0.1+(4200-3000)*0.15+(10000-4200)*0.2+(in-10000)*0.3;
    printf("%.2lf",ans);
    return 0;
}
