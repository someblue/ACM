#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#define N 205
using namespace std;
typedef pair<double,double> pdd;
const int INF=1<<30;
const double eps=1e-6;

int n;
double d[N][N][2],dis[N][N];
pdd p[N];

void cnt()
{
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            dis[i][j]=dis[j][i]=sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)
                                +(p[i].second-p[j].second)*(p[i].second-p[j].second));
}

void show()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==n)
            cout<<d[i][j][0]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==n)
            cout<<d[i][j][1]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
    double ans=INF*1.0;
    for(i=0;i<n;i++)
    {
        cout<<min(ans,min(d[i][n][0],d[i][n][1]));
        cout<<endl;
    }
    cout<<endl;
}

void run()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)    scanf("%lf%lf",&p[i].first,&p[i].second);
    cnt();
    for(i=0;i<n;i++)    d[i][1][0]=d[i][1][1]=0;
    for(j=2;j<=n;j++)
        for(i=0;i<n;i++)
        {
            d[i][j][0]=min(dis[i][(i+1)%n]+d[(i+1)%n][j-1][0],
                        dis[i][(i+j-1)%n]+d[(i+1)%n][j-1][1]);
            d[i][j][1]=min(dis[(i+j-1)%n][(i+j-2)%n]+d[i][j-1][1],
                        dis[(i+j-1)%n][i]+d[i][j-1][0]);
        }
    //show();
    double ans=INF*1.0;
    for(i=0;i<n;i++)
        ans=min(ans,min(d[i][n][0],d[i][n][1]));
    printf("%.3f",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
