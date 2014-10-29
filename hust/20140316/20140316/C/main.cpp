#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("in","r",stdin);
    int q;
    scanf("%d",&q);
    int i;
    long long a,b,res=0;
    char c;
    for(i=0;i<q;i++)
    {
        scanf("%lld%c%c%lld",&a,&c,&c,&b);
        //printf("%lld %c %lld ",a,c,b);
        if(c=='(') res+=b;
        else res-=b;
        //printf("%lld\n",res);
        if(!res) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

/*
AC
*/
