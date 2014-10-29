#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long cacul_n(int t)
{
    if(t==0) return 0;
    long long res;
    res=0;
    while(t--)
    {
        res=res*4+1;
    }
    return res;
}

int div(int n)
{
    int res;
    res=0;
    for(; (n&1)&&n!=0; res++)
        n/=2;
    return res;
}

int min(int a,int b)
{
    return a>b?b:a;
}

int main()
{
    int x,y;
//    while(scanf("%d",&t))
//    {
//        printf("%I64d\n",cacul_n(div(t)));
//        printf("%d\n",div(t));
//    }
    scanf("%d%d",&x,&y);
    printf("%I64d\n",cacul_n( min( div(x),div(y) ) ) );
    return 0;
}
