#include <iostream>
#include <cstdio>
#include <cstring>
#define decode(a,b) ((a)*8+(b))
#define N 80
using namespace std;
const int INF = 1<<28;
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,-2,2,-1,1};

int d[N][N];

inline bool inside(int x,int y)
{
    return x>0 && x<=8 && y>0 && y<=8;
}

void pre()
{
    int i,j,k;
    for(i=0;i<N;++i)   for(j=0;j<N;++j)   d[i][j]=INF;
    for(i=0;i<N;++i)    d[i][i]=0;
    for(i=1;i<=8;++i)
        for(j=1;j<=8;++j)
            for(k=0;k<8;++k)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(!inside(x,y))    continue;
                d[decode(i,j)][decode(x,y)]=1;
            }
    int s=decode(1,1);
    int t=decode(8,8);
    for(k=s;k<=t;++k)
        for(i=s;i<=t;++i)
            for(j=s;j<=t;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    pre();
    char s1[10],s2[10];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int a=decode(s1[0]-'a'+1,s1[1]-'0');
        int b=decode(s2[0]-'a'+1,s2[1]-'0');
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,d[a][b]);
    }
    return 0;
}
