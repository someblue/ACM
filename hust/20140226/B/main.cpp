#include <iostream>
#include <cstdio>
#include <cmath>
#define N 110

using namespace std;

double s[N];
int n;
double vb,vs,xu,yu;
double df,db;

int solve()
{
    int i;
    double t;
    for(i=1;i<n;i++)
        if(s[i]>=xu)
            break;
    if(i==1||i==n) return i+1;
    df=sqrt((xu-s[i-1])*(xu-s[i-1])+yu*yu);
    db=sqrt((xu-s[i])*(xu-s[i])+yu*yu);
//    cout<<df<<' '<<db<<' '<<(s[i]-s[i-1])/vb<<endl;
    t=( (s[i]-s[i-1])/vb + (db-df)/vs );
    if(t>-0.0000001&&t<0.0000001) {return i+1;}
    return t>0?i:i+1;
}

int main()
{
    int i;
    scanf("%d%lf%lf",&n,&vb,&vs);
    for(i=0;i<n;i++)
        scanf("%lf",&s[i]);
    scanf("%lf%lf",&xu,&yu);
    printf("%d",solve());
    return 0;
}
/*
4 5 1
0 10 15 20
13.2 2.4
*/

