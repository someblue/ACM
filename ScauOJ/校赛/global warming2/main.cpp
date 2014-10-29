#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 510

using namespace std;

int a[MAXN][MAXN],vis[MAXN][MAXN],len[MAXN*MAXN];
int m,n,p;

bool dfs(int vis[MAXN][MAXN],int i,int j)
{
    if(vis[i][j]||i<0||i>=m||j<0||j>=n) return 0;
    if(i==m-1&&j==n-1) return 1;
//    cout<<i<<','<<j<<endl;
    vis[i][j]=1;
    bool flag=0;
    flag|=dfs(vis,i-1,j);
    flag|=dfs(vis,i,j-1);
    flag|=dfs(vis,i+1,j);
    flag|=dfs(vis,i,j+1);
    return flag;
}

bool dfs(int h)
{
    memset(vis,0,sizeof(vis));
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(h>a[i][j])
                vis[i][j]=1;
//    cout<<h<<":"<<endl;
//    for(i=0;i<m;i++)
//    {
//        for(j=0;j<m;j++)
//            printf("%d ",vis[i][j]);
//        cout<<endl;
//    }
//    cout<<endl;
    return dfs(vis,0,0);
}

int binary(int p1,int p2)
{
    int m=(p1+p2)/2;
    if(dfs(len[m])&&!dfs(len[m+1])) return len[m];
    else if(dfs(len[m+1])) return binary(m+1,p2);
    else return binary(p1,m-1);
}

int main()
{
    freopen("case.txt","r",stdin);
    memset(a,0,sizeof(a));
    memset(len,0,sizeof(len));
    int i,j,cnt=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            len[cnt++]=a[i][j];
        }
    scanf("%d",&p);
    sort(len,len+cnt);
    cout<<binary(0,cnt-1)/p<<endl;
    return 0;
}
