#include <iostream>
#include <cstdio>

using namespace std;

int pow_n_of_times(int times,int &n)
{
    if(times==1) return n;
    int res,t;
    t=pow_n_of_times(times/2,n);
    res=t*t;
    if(times&1)
        res=res*n;
    return res%10;
}

int quick_pow(int a,int n,int m)
//caculate pow(a,n)%m
{
    int base=a%m,res=1;
    while(n>0)
    {
        if(n&1)res=(res*base)%m;
        base=base*base%m;
        n>>=1;
    }
    return res;
}
//---------text result----------
//---------It do work-----------

int main()
{
    int T,n,mod_n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        mod_n=n%10;
        printf("%d\n",/*pow_n_of_times(n,mod_n)*/quick_pow(mod_n,n,10));
    }
    return 0;
}
