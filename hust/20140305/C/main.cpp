#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010

using namespace std;

int m[N];

int main()
{
    int i,j,k,n,ok;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&m[i]);
    for(i=3;i<=n;i++)
    {
        if(n%i) continue;
        for(j=0,ok=1;j<n/i;j++)
        {
            for(k=j;k<n;k+=n/i)
                if(!m[k]){ok=0;break;}
            if(ok) break;
        }
        if(ok) break;
    }
    printf("%s\n",i<=n/3?"YES":"NO");
    return 0;
}
