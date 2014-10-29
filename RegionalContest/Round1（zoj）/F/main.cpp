#include <bits/stdc++.h>
#define reset(x,y) (x&~(1<<(y)))
#define set(x,y) (x|(1<<(y)))
#define test(x,y) (x&(1<<(y)))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2

bool vis[1<<18],ans[1<<18];
bool edge[9][4];
int times[1<<18];
char g1[10][10][10],g2[10][10][10],tmpg[10][10];

void init()
{
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
}

void rotate_g(char gg[10][10])
{
    for(int i=0;i<8;i++)
        strcpy(tmpg[i],gg[i]);
    for(int j=0;j<8;j++)
        for(int i=0;i<8;i++)
            gg[j][7-i]=tmpg[i][j];
}
bool equ(char a[10][10],char b[10][10])
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(a[i][j]!=b[i][j]) return 0;
    return 1;
}
void flag_ans(int cur,int &s)
{
    if(cur==9) {ans[s]=1; return;}
    for(int i=0;i<4;i++)
    {
        if(equ(g1[cur],g2[cur]))
        {
            s = reset(s,cur<<1);
            s = reset(s,cur<<1|1);
            if(test(i,0))
                s = set(s,cur<<1);
            if(test(i,1))
                s = set(s,cur<<1|1);
            flag_ans(cur+1,s);
        }
        rotate_g(g1[cur]);
    }
}

void read()
{
    for(int r=0;r<3;r++)
        for(int i=0;i<8;i++)
            for(int j=0;j<3;j++)
                scanf("%s",g1[r*3+j][i]);
    for(int r=0;r<3;r++)
        for(int i=0;i<8;i++)
            for(int j=0;j<3;j++)
                scanf("%s",g2[r*3+j][i]);
    for(int i=0;i<9;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&edge[i][j]);
//    for(int i=0;i<9;i++)
//    {
//        for(int j=0;j<8;j++)
//            puts(g1[i][j]);
//        rotate_g(g1[i]);
//        puts("");
//        for(int j=0;j<8;j++)
//            puts(g1[i][j]);
//        puts("----------");
//    }
    int s=0;
    flag_ans(0,s);
}

int dir[10],dir2[10];
bool vis2[10];

int next_dir(int id,int dir)
{
    if(dir==0)
    {
        if(id/3==0) return -1;
        return id-3;
    }
    else if(dir==1)
    {
        if(id%3==2) return -1;
        return id+1;
    }
    else if(dir==2)
    {
        if(id/3==2) return -1;
        return id+3;
    }
    else
    {
        if(id/3==0) return -1;
        return id-1;
    }
}
bool meshed(int x,int y,int d)
{
    int u = 3-dir[x];
    int v = 3-dir[y];
    u = (u+(d+2)%4)%4;
    v = (v+d)%4;
    return u&&v;
}
int next_g(int s,int id)
{
    int res = s;
    for(int i=0;i<9;i++)
        dir[i] = test(s,i<<1) + test(s,i<<1|1)*2;
    memset(vis2,0,sizeof(vis2));
    dir[id]=(dir[id]+1)%4;
    dir2[id]=1; // 1 clock, 0 opposite
    queue<int> que;
    que.push(id);
    while(!que.empty())
    {
        int u = que.front(); que.pop();
        for(int i=0;i<4;i++)// 0 up, 1 right, 2 down, 3 left
        {
            int v = next_dir(u,i);
            if(v==-1 || vis[v]) continue;
            if(!meshed(u,v,i)) continue;
            vis[v] = 1;
            if(dir2[u]==1)
            {
                dir2[v]=0;
                dir[v]--; if(dir[v]<0) dir[v]+=4;
            }
            else
            {
                dir2[v]=1;
                dir[v]++; dir[v]%=4;
            }
            res = reset(res,v<<1);
            res = reset(res,v<<1|1);
            if(test(i,0)) res = set(res,v<<1);
            if(test(i,1)) res = set(res,v<<1|1);
            que.push(v);
        }
    }
    return res;
}

void print(int x)
{
    for(int i=0;i<9;i++)
    {
        printf("%d ",x%4);
        x/=4;
    }
    puts("");
}

int bfs()
{
    queue<int> que;
    que.push(0);
    times[0]=0;
    if(ans[0]) return 0;
    while(!que.empty())
    {
        int u = que.front();    que.pop();
        for(int i=0;i<9;i++)
        {
            int nxt = next_g(u,i);
            print(nxt);
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            times[nxt] = times[u]+1;
            if(ans[nxt])
                return times[nxt];
            que.push(nxt);
        }
    }
    return -1;
}

void run()
{
    init();
    read();
    printf("%d\n",bfs());
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
