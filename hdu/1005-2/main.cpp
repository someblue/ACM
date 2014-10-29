#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100
using namespace std;
int arr[N],s,e,a,b,n;
void solve()
{
    int i,j;
    arr[1]=arr[2]=1;
    for(i=3;;i++)
    {
        arr[i]=(a*arr[i-1]+b*arr[i-2])%7;
        for(j=2;j<i;j++)
            if(arr[j-1]==arr[i-1]&&arr[j]==arr[i])
            {
                s=j,e=i;
                return;
            }
    }
}
int main()
{
    while(scanf("%d%d%d",&a,&b,&n)!=EOF && a)
    {
        solve();
        printf("%d\n",n<=e?arr[n]:arr[s+(n-e)%(e-s)]);
    }
    return 0;
}
