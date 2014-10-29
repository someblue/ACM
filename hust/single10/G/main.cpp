#include <bits/stdc++.h>
#define argue px,py,rb1.x,rb1.y,rb1.dir,rb2.x,rb2.y,rb2.dir
#define argue2 nx,ny,nrb1.x,nrb1.y,nrb1.dir,nrb2.x,nrb2.y,nrb2.dir
using namespace std;
const int N = 10;
const int STATEN = 5000000;

const int dx[]={0,-1,1,0,0};
const int dy[]={1,0,0,-1,0};
const char dc[]="ENSWX";
const int bitw[]={1,8,8*8,8*8*8,8*8*8*8,8*8*8*8*4,8*8*8*8*4*8,8*8*8*8*4*8*8};

char g[N][N];

struct _state{
    int st,fa;
    char dir;
    bool vis;
    bool operator == (const _state &b) const
    {
        return st == b.st;
    }
};

int pos_to_hash(int px,int py,int r1x,int r1y,int r1d,int r2x,int r2y,int r2d)
{
    int res=0;
    px--;py--;
    r1x--;r1y--;
    r2x--;r2y--;
    res=px*bitw[0] + py*bitw[1] + r1x*bitw[2] + r1y*bitw[3] + r1d*bitw[4]
                + r2x*bitw[5] + r2y*bitw[6] + r2d*bitw[7];
    return res;
}

void hash_to_pos(int st,int &px,int &py,int &r1x,int &r1y,int &r1d,int &r2x,int &r2y,int &r2d)
{
    r2d=st/bitw[7]; st%=bitw[7];
    r2y=st/bitw[6]; st%=bitw[6]; r2y++;
    r2x=st/bitw[5]; st%=bitw[5]; r2x++;
    r1d=st/bitw[4]; st%=bitw[4];
    r1y=st/bitw[3]; st%=bitw[3]; r1y++;
    r1x=st/bitw[2]; st%=bitw[2]; r1x++;
    py =st/bitw[1]; st%=bitw[1]; py++;
    px =st/bitw[0]; st%=bitw[0]; px++;
}

int direction_to_int(char c)
{
    for(int i=0;i<5;++i)
        if(dc[i]==c)
            return i;
    return -1;
}

struct _robot{
    int x,y,dir;
    _robot() {}
    _robot(int _x,int _y,int _dir) {x=_x;y=_y;dir=_dir;}
    _robot move(int px,int py,int px2,int py2)
    {
        int nx,ny;
        for(int i=0;i<4;++i)
        {
            nx=x,ny=y;
            bool flag=0;
            while(g[nx][ny]!='#' && g[nx][ny]!='T')
            {
                nx+=dx[i],ny+=dy[i];
                if((nx==px && ny==py) || (nx==px2 && ny==py2))
                {
                    dir=i;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        int cnt=0;
        for(cnt=0;cnt<4;++cnt)
        {
            nx=x+dx[dir],ny=y+dy[dir];
            if(g[nx][ny]!='#' && g[nx][ny]!='T')    break;
            if(dir==0)  dir=2;
            else if(dir==2) dir=3;
            else if(dir==3) dir=1;
            else dir=0;
        }
        if(cnt<4)   return _robot(nx,ny,dir);
        return _robot(x,y,dir);
    }
};

int n;
int px,py;
_robot rb1,rb2;
_state st[STATEN];

void pre()
{
    char tc;
    scanf("%c",&tc);
    for(int i=0;i<n;++i)
        gets(g[i]);
    int cnt=1;
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
    {
        if(g[i][j]=='X')
            px=i,py=j;
        else if(g[i][j]=='#' || g[i][j]=='T' || g[i][j]==' ')
            continue;
        else
        {
            if(cnt==1)
                rb1.x=i, rb1.y=j, cnt++,
                rb1.dir=direction_to_int(g[i][j]);
            else
                rb2.x=i, rb2.y=j,
                rb2.dir=direction_to_int(g[i][j]);
        }
    }
    for(int i=0;i<STATEN;++i)
        st[i].vis=0;
}

char g2[N][N];
void showgraph_init()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
    {
        if(g[i][j]=='#' || g[i][j]=='T')
            g2[i][j]=g[i][j];
        else
            g2[i][j]=' ';
    }
}
void showgraph(int s)
{
    hash_to_pos(s,argue);
    g[px][py]='X';
    g[rb1.x][rb1.y]=dc[rb1.dir];
    g[rb2.x][rb2.y]=dc[rb2.dir];
    cout<<"-----------"<<endl;
    for(int i=0;i<n;++i)
        puts(g[i]);
    g[px][py]=' ';
    g[rb1.x][rb1.y]=' ';
    g[rb2.x][rb2.y]=' ';
}

void print(int s)
{
    vector<char> ans;
    int ns;
//    showgraph_init();
    while(true)
    {
        ns = st[s].fa;
//        showgraph(ns);
        if(ns==-1)  break;
        ans.push_back(st[s].dir);
        s = ns;
    }
    for(int i=ans.size()-1;i>=0;--i)
        printf("%c",ans[i]);
    printf("\n");
}

bool bfs()
{
    int nx,ny;
    _robot nrb1,nrb2;
//    cout<<px<<' '<<py<<endl;
//    cout<<rb1.x<<' '<<rb1.y<<' '<<rb1.dir<<endl;
//    cout<<rb2.x<<' '<<rb2.y<<' '<<rb2.dir<<endl;
    int now_state = pos_to_hash(argue);
//    cout<<now_state<<endl;
    st[now_state].fa = -1;
    st[now_state].vis = 1;
    queue<int> que;
    que.push(now_state);
    while(!que.empty())
    {
        now_state = que.front();
        que.pop();
        hash_to_pos(now_state,argue);
        for(int i=0;i<5;++i)
        {
            nx=px+dx[i];
            ny=py+dy[i];
            if(g[nx][ny]=='T')
            {
                px=nx; py=ny;
                int t_state = pos_to_hash(argue);
                st[t_state].dir = dc[i];
                st[t_state].fa  = now_state;
                print(t_state);
                return 1;
            }
            if(g[nx][ny]=='#')
                continue;
            if((nx==rb1.x && ny==rb1.y) || (nx==rb2.x && ny==rb2.y))
                continue;
            nrb1=rb1.move(nx,ny,px,py);
            nrb2=rb2.move(nx,ny,px,py);
            if((nrb1.x==nx&&nrb1.y==ny) || (nrb2.x==nx && nrb2.y==ny))
                continue;
            int n_state = pos_to_hash(argue2);
            if(st[n_state].vis) continue;
            st[n_state].vis = 1;
            st[n_state].fa = now_state;
            st[n_state].dir = dc[i];
            que.push(n_state);
        }
    }
    return 0;
}

int main()
{
    freopen("case.txt","r",stdin);
    for(int i=0;i<STATEN;++i)
        st[i].st = i;
    while(scanf("%d",&n)!=EOF && n)
    {
        pre();
        if(!bfs())
            puts("You can't escape...");
    }
    return 0;
}
