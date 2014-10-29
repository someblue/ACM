#include <iostream>
#include <cstdio>
using namespace std;

double fact(int n)
{
    if(!n) return 1.0;
    int res=1;
    for(int i=1;i<=n;i++)   res*=i;
    return res*1.0;
}

double cnte(int n)
{
    double e=0;
    for(int i=0;i<=n;i++) e+=1.0/fact(i);
    return e;
}

int main()
{
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    cout<<"0 1"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 2.5"<<endl;
    for(int i=3;i<=9;i++)
        printf("%d %.9lf\n",i,cnte(i));
    return 0;
}
