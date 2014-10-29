#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>
#define REP(i,n) for(i=0;i<(n);++i)
using namespace std;
const int N = 505;

int a[N][N],b[N][N],c[N][N];
int n;

void run()
{
    int i,j,k;
    int x,y,t;
    REP(i,n) REP(j,n)
        scanf("%d",&a[i][j]);
    REP(i,n) REP(j,n)
        scanf("%d",&b[i][j]);
    REP(i,n) REP(j,n)
        scanf("%d",&c[i][j]);
    for(k=50000;k;--k)
    {
        x=rand()%n;
        y=rand()%n;
        for(i=0,t=0;i<n;++i)
            t+=a[x][i]*b[i][y];
        if(t!=c[x][y])
            break;
    }
    printf("%s\n",k?"NO":"YES");
}

int main()
{
    srand(time(NULL));
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
