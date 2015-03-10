#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 2010;
int cas = 1;

typedef pair<int,int> point;
int cnt[N][N], n, m;
char g[N][N];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const char s1[] = {'^','v','<','>'};
const char s2[] = {'v','^','>','<'};

bool bfs() {
    int i,j,dir;
    queue<point> que;
    rep(i,1,n+1) rep(j,1,m+1) if(g[i][j]=='.') {
        if(cnt[i][j]<=0) return 0;
        if(cnt[i][j]==1) {
            que.push(point(i,j));
            while(!que.empty()) {
                pii u = que.front();
                que.pop();
                if(g[u.fi][u.se]!='.') continue;
                if(cnt[u.fi][u.se]!=1) return 0;
                rep(dir,0,4) {
                    if(g[u.fi+dx[dir]][u.se+dy[dir]]=='.')
                        break;
                }
                pii v(u.fi+dx[dir], u.se+dy[dir]), t;
                g[u.fi][u.se] = s1[dir];
                g[v.fi][v.se] = s2[dir];
                rep(dir,0,4) {
                    t = pii(u.fi+dx[dir], u.se+dy[dir]);
                    if(g[t.fi][t.se]=='.') {
                        cnt[t.fi][t.se]--;
                        if(cnt[t.fi][t.se]==1)
                            que.push(t);
                    }
                    t = pii(v.fi+dx[dir], v.se+dy[dir]);
                    if(g[t.fi][t.se]=='.') {
                        cnt[t.fi][t.se]--;
                        if(cnt[t.fi][t.se]==1)
                            que.push(t);
                    }
                }
            }
        }
    }
    rep(i,1,n+1) rep(j,1,m+1) if(g[i][j]=='.') return 0;
    return 1;
}

void run()
{
    int i,j,k;
    rep(i,1,n+1) scanf("%s", g[i]+1);
    rep(i,0,n+2) g[i][0] = g[i][m+1] = '*';
    rep(j,0,m+2) g[0][j] = g[n+1][j] = '*';
    MS(cnt);
    bool fg = 0;
    rep(i,1,n+1) rep(j,1,m+1) if(g[i][j]=='.') {
        rep(k,0,4) if(g[i+dx[k]][j+dy[k]]=='.') cnt[i][j]++;
        if(cnt[i][j]==0) {
            fg = 1;
            goto bk;
        }
    }
    bk:
    if(fg || bfs()==0) {
        puts("Not unique");
        return;
    }
    rep(i,1,n+1) {
        rep(j,1,m+1) putchar(g[i][j]);
        puts("");
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin >> n >> m)
        run();
    return 0;
}
