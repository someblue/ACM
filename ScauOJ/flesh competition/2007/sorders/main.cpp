#include <iostream>
#include <cstdio>

using namespace std;

int div(unsigned k)
{
    if(k<3) return 0;
    if(k==3) return 1;
    if(k&1)
    {
        return div(k>>1)+div((k>>1)+1);
    }
    else
    {
        return 2*div(k>>1);
    }
}

int main()
{
    unsigned n;
    while(scanf("%d",&n),n!=0)
    {
        printf("%d\n",div(n));
    }
//    cnt=0;
//    div(10);
//    printf("%d\n",cnt);
    return 0;
}
