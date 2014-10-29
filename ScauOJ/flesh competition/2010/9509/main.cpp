#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = (1<<16);
const int sss = maxn-1;
bool vis[maxn];
int xornum[16],s;
char str[5][5];

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        int tmp = s;
        for(int i=0;i<16;i++)
            if(u&(1<<i))
                tmp^=xornum[i];
        if(tmp==sss) return u;
        for(int i=0;i<16;i++)
        {
            int tmp = (u|(1<<i));
            if(vis[tmp]) continue;
            vis[tmp]=1;
            que.push(tmp);
        }
    }
    return sss;
}

void run()
{
    int i,j;
    s=0;
    for(i=0;i<4;i++)
    {
        scanf("%s",str[i]);
        for(j=0;j<4;j++)
            if(str[i][j]=='1')
                s|=(1<<(i*4+j));
    }
    if(s==sss)
    {
        puts("0");
        return;
    }
    int tmp = bfs();
//    cout<<tmp<<endl;
    int ans = 0;
    for(i=0;i<16;i++) if(tmp&(1<<i)) ans++;
    printf("%d",ans);
}

void pre()
{
    memset(xornum,0,sizeof(xornum));
    for(int k=0;k<16;k++)
    {
        int i,j;
        i=k/4;
        for(j=0;j<4;j++)
            xornum[k]|=(1<<(i*4+j));
        j=k%4;
        for(i=0;i<4;i++)
            xornum[k]|=(1<<(i*4+j));
    }
}

int main()
{
    pre();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
