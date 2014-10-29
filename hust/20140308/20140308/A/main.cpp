#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 510

using namespace std;

int t[N];

int main()
{
    int n,ip,k,ip2;
    int i,j,ci;
    while(scanf("%d%d",&n,&ip)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&t[i]);
        sort(t,t+n);
//        for(i=n-1;i>=0;i--)
//            if(ip<=t[i]) break;
//        ci=i;
        ci=0;
        k=0;
        for(;ci<n;ci++)
        {
            if(ip<t[ci]){k++;ip+=2;}
        }
        printf("%d\n",ip+n-k);
    }
    return 0;
}
