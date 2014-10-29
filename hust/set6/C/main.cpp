#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,n) for(i=1;i<=(n);++i)
#define N 1005
using namespace std;
const double eps = 0.0000001;

double d[N][N];
int n;

void run()
{
    int i,j,k;
    FOR(i,n)    FOR(j,n)
//    for(i=1;i<=n;++i)   for(j=1;j<=n;++j)
        scanf("%lf",&d[i][j]);
    FOR(k,n) FOR(i,n) FOR(j,n)
//    for(k=1;k<=n;++k)   for(i=1;i<=n;++i)   for(j=1;j<=n;++j)
        if(d[i][k]*d[k][j] > d[i][j])   d[i][j]=d[i][k]*d[k][j];
    int m,a,b;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(abs(d[a][b]-0.0)<eps)    puts("What a pity!");
        else    printf("%.3f\n",d[a][b]);
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
