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

void printstu()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d,%d\n",stu[i*n+j].x,stu[i*n+j].y);
    }
}
void run()
{
    int ans,l,minl;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
    {
        ans=INF;
        memset(stu,0,sizeof(stu));
        int i;
        for(i=0;i<n*n;i++)
            scanf("%d%d",&stu[i].x,&stu[i].y);
        sort(stu,stu+n*n);
        printstu();
        for(l=1;l+n-1<=m;l++)
        {
            ans=min(ans,cntsquare(l));
        }
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
AC
*/
