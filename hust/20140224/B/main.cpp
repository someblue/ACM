#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110

using namespace std;

char desk[N][N],check[128],pc;
int m,n;

bool isp(int i,int j)
{
    if(i<0||i>=m||j<0||j>=n) return 0;
    if(desk[i][j]==pc) return 1;
    return 0;
}

int main()
{
    int i,j,ans;
    char tc,c;
    scanf("%d%d%c%c%c",&m,&n,&tc,&pc,&tc);
    for(i=0;i<m;i++)
        gets(desk[i]);
    memset(check,0,sizeof(check));
    ans=0;
    check[pc]=1;check['.']=1;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            c=desk[i][j];
            if(check[c]) continue;
            if(isp(i-1,j)||isp(i+1,j)||isp(i,j-1)||isp(i,j+1))
            {
                check[c]=1;
                ans++;
            }
        }
    printf("%d\n",ans);
    return 0;
}
