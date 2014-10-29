#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define VI vector<int>
#define N  60
const int INF=99999999;
typedef long long ll;
using namespace std;
struct node{
    int x,y;
    friend bool operator < (node a,node b)
    {
        return a.x<b.x||(a.x==b.x&&a.y<b.y);
    }
};
node stu[N*N];
int n,m;
int cntline(int l,int line)
{
    int i,res=0;
    for(i=0;i<n;i++)
        res+=abs(l+i-stu[line*n+i].y);
    return res;
}
int cntsquare(int l)
{
    int i,res=0;
    for(i=0;i<n;i++)
    {
        res+=cntline(l,i);
    }
    return res;
}
//void input()
//{
//    int cnt=0;
//    int x,y;
//    while(scanf("%d%d",&x,&y),!(x==0&&y==0))
//    {
//        stu[cnt].x=x;
//        stu[cnt].y=y;
//        cnt++;
//    }
//}
//void printstu()
//{
//    int i,j;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//            printf("%d,%d\n",stu[i*n+j].x,stu[i*n+j].y);
//    }
//}
void run()
{
    int ans,l,minl,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=INF;
        memset(stu,0,sizeof(stu));
//        input();
//        int cnt=0;
//        int x,y;
//        while(scanf("%d%d",&x,&y)!=EOF)
//        {
//            if(x==0&&y==0) break;
//            stu[cnt].x=x;
//            stu[cnt].y=y;
//            cnt++;
//        }
        int i;
        for(i=0;i<n*n;i++)
            scanf("%d%d",&stu[i].x,&stu[i].y);
        scanf("%d%d",&t,&t);
        sort(stu,stu+n*n);
//        printstu();
        for(l=1;l+n-1<=m;l++)
        {
            //if(cntsquare(l)<ans) minl=l;
            ans=min(ans,cntsquare(l));
        }
        //cout<<minl<<endl;
        printf("%d\n",ans);
    }
}

int main()
{
    //freopen("in","r",stdin);
    run();
    return 0;
}

/*
WA
*/
