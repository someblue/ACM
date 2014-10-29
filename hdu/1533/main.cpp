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
#define N 105
using namespace std;
typedef pair<int,int> pii;
const int INF=1<<30;
const double eps=1e-6;

int lx[N],ly[N];
int mx[N],my[N];
bool vx[N],vy[N];
int w[N][N],n;

pii ox[N],oy[N];
int xcnt,ycnt;
int X,Y;

bool match(int x)
{
    vx[x]=1;
    for(int y=0;y<n;++y)
        if(lx[x]+ly[y]==w[x][y] && !vy[y])
        {
            vy[y]=1;
            if(my[y]==-1 || match(my[y]))
            {
                my[y]=x;
                mx[x]=y;
                return 1;
            }
        }
    return 0;
}

void update()
{
    int d=INF,i,j;
    for(i=0;i<n;++i) if(vx[i])
        for(j=0;j<n;++j) if(!vy[j])
            d=min(d,lx[i]+ly[j]-w[i][j]);
    if(d==INF)  return;
    for(i=0;i<n;++i)
    {
        if(vx[i])   lx[i]-=d;
        if(vy[i])   ly[i]+=d;
    }
}

int km()
{
//    memset(lx,0,sizeof(lx));
    for(int i=0;i<n;++i)    lx[i]=-INF;
    memset(ly,0,sizeof(ly));
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            lx[i]=max(lx[i],w[i][j]);//ע�⸺Ȩ
    for(i=0;i<n;++i)
        while(true)
        {
            memset(vx,0,sizeof(vx));
            memset(vy,0,sizeof(vy));
            if(match(i))    break;
            else    update();
        }
    int res=0;
    for(int y=0;y<n;++y)
        res+=w[my[y]][y];
    return -res;
}

void run()
{
    char s[N];
    int i,j;
    xcnt=ycnt=0;
    for(i=0;i<X;++i)
    {
        scanf("%s",s);
        for(j=0;j<Y;++j)
        {
            if(s[j]=='H')
            {
                ox[xcnt].first=i;
                ox[xcnt].second=j;
                ++xcnt;
            }
            else if(s[j]=='m')
            {
                oy[ycnt].first=i;
                oy[ycnt].second=j;
                ++ycnt;
            }
        }
    }
    n=xcnt;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            w[i][j]= -(abs(ox[i].first - oy[j].first) + abs(ox[i].second - oy[j].second));
    printf("%d\n",km());
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&X,&Y)!=EOF && X)
        run();
    return 0;
}
