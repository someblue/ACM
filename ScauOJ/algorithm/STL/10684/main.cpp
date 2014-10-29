#include <iostream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define N 10010

using namespace std;

struct node
{
    int x,y,dis;
    void cntdis(node bai)
    {
        dis = abs(x-bai.x)+abs(y-bai.y);
    }
    friend bool operator < (node a,node b)
    {
        return a.dis<b.dis||(a.dis==b.dis&&a.x<b.x)||(a.dis==b.dis&&a.x==b.x&&a.y<b.y);
    }
    void print()
    {
        //cout<<x<<' '<<y<<endl;
        printf("%d %d\n",x,y);
    }
};

node bai,mm[N];
int n;

int findid(int k)
{
    int i;
    for(i=0; i < n; i++)
        if(mm[i].dis>=k) return i;
    return -1;
}

void run()
{
    int m,i,t,id;
    //while(cin>>bai.x>>bai.y)
    while(scanf("%d%d",&bai.x,&bai.y)!=EOF)
    {
        //cin>>n;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            //cin>>mm[i].x>>mm[i].y;
            scanf("%d%d",&mm[i].x,&mm[i].y);
            mm[i].cntdis(bai);
        }
        sort(mm,mm+n);
        //cin>>m;
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            //cin>>t;
            scanf("%d",&t);
            id=findid(t);
            if(id!=-1) mm[id].print();
            //else cout<<-1<<endl;
            else printf("-1\n");
        }
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    //std::ios::sync_with_stdio(0);
    run();
    return 0;
}
/*
WA:if dis is equal, print the minimal x y.
WA:multi case
TLE:sync with stdio
TLE:scanf()!=EOF
AC
*/
