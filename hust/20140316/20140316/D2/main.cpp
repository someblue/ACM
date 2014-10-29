#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define VI vector<int>
typedef long long ll;
using namespace std;

int main()
{
    int a,b,c,n,i,j,ans;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    ans=0;
    for(i=0;a*i<=n;i++)
    {
        for(j=0;a*i+b*j<=n;j++)
        {
            if((n-a*i-b*j)%c) continue;
            ans = max(ans,i+j+(n-a*i-b*j)/c);
        }
    }
    printf("%d\n",ans);
    return 0;
}

/*
AC
*/
