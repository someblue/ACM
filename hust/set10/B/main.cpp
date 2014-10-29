#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;
const int mod = 10000;

struct _martix{
    int m[2][2];
    friend _martix operator * (const _martix &a,const _martix &b)
    {
        _martix res;
        int i,j,k;
        for(i=0;i<2;++i)
            for(j=0;j<2;++j)
        {
            res.m[i][j]=0;
            for(k=0;k<2;++k)
                res.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
        }
        return res;
    }
    void reset()
    {
        m[0][0]=m[0][1]=m[1][0]=1;
        m[1][1]=0;
    }
};

_martix martix_pow(_martix a,int n)
{
    _martix res;
    res.reset();
    if(n==1)    return res;
    _martix t = martix_pow(a,n/2);
    res = t*t;
    if(n&1) res = res*a;
    return res;
}

int n;
_martix mtx;

void run()
{
    if(n==0)    {puts("0");return;}
    mtx.reset();
    mtx = martix_pow(mtx,n);
    printf("%d\n",mtx.m[0][1]%mod);
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF && n!=-1)
        run();
    return 0;
}
