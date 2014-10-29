#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110

using namespace std;

char s[N][N];

int main()
{
    freopen("in","r",stdin);
    int n,m,i,j,ok;
    scanf("%d%d",&n,&m);
    gets(s[0]);
    for(i=0;i<n;i++)
        gets(s[i]);
//    for(i=0;i<n;i++)
//        puts(s[i]);
    ok=1;
    for(i=0;i<n;i++)
        for(j=1;j<m;j++)
            if(s[i][j]!=s[i][j-1]) {ok=0;break;}
    if(ok==1)
        for(i=1;i<n;i++)
            if(s[i][0]==s[i-1][0]) {ok=0;break;}
    printf("%s\n",ok?"YES":"NO");
    return 0;
}
