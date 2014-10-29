#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int _;
    double res;
    int n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        res=0.0;
        for(int i=1;i<=n;++i)
            res+=log10((double)i);
        printf("%d\n",(int)res+1);
    }
    return 0;
}
