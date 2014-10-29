#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
#define INF 90000001

using namespace std;

inline int minnum(int a,int b)
{
    return a<b?a:b;
}

int d[N][N];

int main()
{
    int n,m,i,u,v,w,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                d[i][j] = INF;
            d[i][i]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            d[u][v] = minnum(w,d[u][v]);
            d[v][u] = d[u][v];
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
            {
                if(d[i][k]==INF) continue;
                for(j=0;j<n;j++)
                    d[i][j] = minnum(d[i][j],d[i][k]+d[k][j]);
            }
        int a,b;
        scanf("%d%d",&a,&b);
        if(d[a][b]==INF) printf("-1\n");
        else printf("%d\n",d[a][b]);
    }
    return 0;
}
