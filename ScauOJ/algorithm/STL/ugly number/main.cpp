#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define VLL vector<long long>
#define N 1510
typedef long long LL;
using namespace std;
VLL u;
inline void next(int &t,int k,int maxn)
{
    while(u[t]*k<=maxn) t++;
}
void maketable()
{
    LL maxn;
    int t2,t3,t5;
    u.push_back(1);
    maxn=0;
    t2=t3=t5=0;
    while(u.size()<N)
    {
        maxn=u[u.size()-1];
        next(t2,2,maxn);
        next(t3,3,maxn);
        next(t5,5,maxn);
        u.push_back(min(min(u[t2]*2,u[t3]*3),u[t5]*5));
    }
}
void run()
{
    maketable();
    int n;
    while(scanf("%d",&n),n!=0)
    {
        printf("%I64d\n",u[--n]);
    }
}
int main()
{
    run();
    return 0;
}

/*
AC
*/
