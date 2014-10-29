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
#define REP(i,n) for(i=0;i<(n);++i)
#define N 55
#define NN 1300
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

struct _edge{
    int to,next;
};
_edge edge[N*N];int edge_cnt;
int first[NN];
int nx,ny;
int mx[NN],my[NN];
bool vy[NN];

char s[N][N];
int R,C;
int x[N][N],y[N][N];
int xcnt,ycnt;

bool dfs(int x)
{
    for(int e=first[x];e!=-1;e=edge[e].next)
    {
        int &y=edge[e].to;
        if(!vy[y])
        {
            vy[y]=1;
            if(my[y]==-1 || dfs(my[y]))
            {
                my[y]=x;
                mx[x]=y;
                return 1;
            }
        }
    }
    return 0;
}

int b_match()
{
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int res=0;
    for(int i=0;i<nx;++i)
    {
        memset(vy,0,sizeof(vy));
        if(dfs(i))  ++res;
    }
    return res;
}

void add_edge(int from,int to)
{
    edge[edge_cnt].to = to;
    edge[edge_cnt].next = first[from];
    first[from]=edge_cnt;
    ++edge_cnt;
}

void run()
{
    int i,j,ii,jj;
    memset(x,-1,sizeof(x));
    memset(y,-1,sizeof(y));
    memset(first,-1,sizeof(first));
    xcnt=ycnt=0;edge_cnt=0;
    REP(i,R)    scanf("%s",s[i]);
//    cout<<"---------------------"<<endl;
//    REP(i,R)    printf("%s\n",s[i]);
//    cout<<"---------------------"<<endl;
    REP(i,R) REP(j,C)
    {
        if(s[i][j]=='*')
        {
            if(x[i][j]==-1)
            {
                for(ii=i;s[ii][j]=='*'&&ii<R;++ii)  x[ii][j]=xcnt;
                ++xcnt;
            }
            if(y[i][j]==-1)
            {
                for(jj=j;s[i][jj]=='*'&&jj<C;++jj)  y[i][jj]=ycnt;
                ++ycnt;
            }
            add_edge(x[i][j],y[i][j]);
        }
    }
//    cout<<"------x------"<<endl;
//    REP(i,R)
//    {
//        REP(j,C)    if(x[i][j]!=-1)cout<<x[i][j];else cout<<' ';
//        cout<<endl;
//    }
//    cout<<"------y------"<<endl;
//    REP(i,R)
//    {
//        REP(j,C)    if(y[i][j]!=-1)cout<<y[i][j];else cout<<' ';
//        cout<<endl;
//    }
    nx=xcnt;ny=ycnt;
//    cout<<nx<<' '<<ny<<endl;
    cout<<b_match()<<endl;
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&R,&C)!=EOF)
        run();
    return 0;
}
