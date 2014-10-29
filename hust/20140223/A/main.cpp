#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int isint(double k)
{
    double a=k-floor(k+0.5);
    return a>-0.000000001&&a<0.0000000001;
}

int main()
{
    double ak,k;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&ak);
        k=sqrt(2*ak-1.75)+0.5;
        printf("%d\n",isint(k));
    }
    return 0;
}
