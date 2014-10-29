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
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 100005;

int next[N][2];
int oper[N][3];
int n,m;

void _swap(int x,int y)
{
    int lst,nxt;
    if(next[x][0]==y)
    {
        lst = next[x][1];
        nxt = next[y][0];
        next[lst][0] = y;
        next[nxt][1] = x;
        next[x][0] = nxt;
        next[x][1] = y;
        next[y][0] = x;
        next[y][1] = lst;
    }
    else if(next[y][0]==x)
    {

    }
}

void init()
{
    l[0][0]=1;
    l[0][1]=-1;
    l[n+1][0]=-1;
    l[n+1][1]=n;
    for(int i=1;i<=n;++i)
        l[i][0]=i+1,l[i][1]=i-1;
}

void test()
{
    int n,x,y;
    cin>>n;
    init();
    while(cin>>x>>y)
}

void run()
{
    init();
    bool four=0;
    for(int i=0;i<m;++i)
    {
        scanf("%d",&oper[i][0]);
        if(oper[i][0]==4)
        {
            four = !four;
            continue;
        }
        scanf("%d%d",&oper[i][1],&oper[i][2]);
        if(oper[i][0]==4)
            _swap(oper[i][1],oper[i][2]);
        else if((oper[i][0]-1) ^ four)
            move_right(oper[i][1],oper[i][2]);
        else
            move_left(oper[i][1],oper[i][2]);
    }
    ll ans=0;
    int k;
    bool odd;
    for(odd=0,k=four?n+1:0; k!=-1; k=next[k][four],odd=!odd)
        if(odd) ans+=k;
    printf("%lld\n",ans);
}

int main()
{
    test();
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
