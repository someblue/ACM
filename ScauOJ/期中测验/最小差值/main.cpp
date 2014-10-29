#include <iostream>
#include <cstdio>

using namespace std;

double abs(double a,double b)
{
    return a>b?a-b:b-a;
}

double min(double a,double b)
{
    return a<b?a:b;
}

int main()
{
    double num[10];
    int i,j;
    for(i=0;i<10;i++)
        cin>>num[i];
    double ans=abs(num[0],num[1]);
    for(i=0;i<10;i++)
        for(j=i+1;j<10;j++)
        {
            ans=min(ans,abs(num[i],num[j]));
        }
    printf("%.2lf",ans);
    return 0;
}
