#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 21
#define INF 1000000
typedef long long ll;
using namespace std;
int h[N][3],n,data[N][3];
int minn(int a,int b)
{
    return a<b?a:b;
}
int next(int x,int y)
{
    if(x>=n) return 0;
    if(data[x][y]) return data[x][y];
    int i,res;
    res=INF;
    for(i=0;i<3;i++)
    {
        if(i==y) continue;
        res=minn(res,next(x+1,i));
    }
    //printf("(%d,%d):%d\n",x,y,res+h[x][y]);
    return data[x][y]=h[x][y]+res;
}
//int next1(int x,int y)
//{
//    if(x>=n) return 0;
//    switch(y)
//    {
//        case 0: return h[x][y]+maxn( next(x+1,1),next(x+1,2) );
//        case 1: return h[x][y]+maxn( next(x+1,0),next(x+1,2) );
//        case 2: return h[x][y]+maxn( next(x+1,0),next(x+1,1) );
//    }
//    exit(-1);
//    return 0;
//}
void run()
{
    int t,cas=1;
    int i;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d%d",&h[i][0],&h[i][1],&h[i][2]);
//        for(i=0;i<n;i++)
//            printf("%d %d %d\n",h[i][0],h[i][1],h[i][2]);
        //ans=maxn(next(0,1),next(0,2),next(0,3));
        ans=INF;
        memset(data,0,sizeof(data));
        for(i=0;i<3;i++)
        {
            ans=minn(ans,next(0,i));
        }
        printf("Case %d: %d\n",cas++,ans);
    }
}
int main()
{
    run();
    return 0;
}
