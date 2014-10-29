#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 510

using namespace std;

int a[MAXN][MAXN],vis[MAXN][MAXN],len[MAXN*MAXN];
int datalen[MAXN*MAXN];
int m,n,p;

bool dfs(int vis[MAXN][MAXN],int i,int j)
{
    if(vis[i][j]!=1||i<0||j>=n) return 0;
    vis[i][j]=-1;
    if(i==m-1||j==0) return 1;
    bool flag=0;
    flag|=dfs(vis,i-1,j-1);flag|=dfs(vis,i-1,j);flag|=dfs(vis,i-1,j+1);
    flag|=dfs(vis,i,j-1);                       flag|=dfs(vis,i,j+1);
    flag|=dfs(vis,i+1,j-1);flag|=dfs(vis,i+1,j);flag|=dfs(vis,i+1,j+1);
    return flag;
}

bool dfs(int h)
{
    //if(datalen[h]!=-1) return datalen[h];
    memset(vis,0,sizeof(vis));
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            if(h>a[i][j])
                vis[i][j]=1;
    i=0;
    for(j=1;j<n;j++)
    {
        if(vis[i][j])
            if(dfs(vis,i,j))
            {
                //datalen[h]=1;
                return 1;
            }
    }
    j=n-1;
    for(i=1;i<m-1;i++)
    {
        if(vis[i][j])
            if(dfs(vis,i,j))
            {
                //datalen[h]=1;
                return 1;
            }
    }
//    datalen[h]=0;
//    return datalen[h];
    return 0;
}

int binary(int p1,int p2)
{
    int m=(p1+p2)/2;
    if(!dfs(len[m])&&dfs(len[m+1])) return len[m];
    else if(dfs(len[m])) return binary(p1,m);
    else return binary(m+1,p2);
}

int main()
{
    freopen("case.txt","r",stdin);
    memset(a,0,sizeof(a));
    memset(len,0,sizeof(len));
    //memset(datalen,-1,sizeof(datalen));
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
    cout<<binary(0,cnt)/p<<endl;
    return 0;
}
