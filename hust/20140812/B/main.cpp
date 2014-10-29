#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
#define REP(i, n) for(int i=0; i<n; i++)
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define xx first
#define yy second
#define CLR(a, b) memset(a, b, sizeof(a))
#define debug puts("****debug****")
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1000010;
const int maxn = 100010;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
int cover[N << 2];
int c[N << 2];
int f[maxn], ansx[maxn];
int n, m;
struct seg{
    int x1, y1, x2, y2;
    bool operator<(const seg &b) const
    {
        return y1 < b.y1;
    }
}g[maxn];

void pushdown(int rt)
{
    if (cover[rt] != -1)///!!!
    {
        cover[rt << 1] = cover[rt << 1 | 1] = cover[rt], cover[rt] = -1;
    }
}
void update(int L, int R, int i, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        cover[rt] = i;
        return ;
    }
    int m = (l + r) >> 1;
//    pushdown(rt);
    if (cover[rt] != -1)
    cover[rt << 1] = cover[rt << 1 | 1] = cover[rt], cover[rt] = -1;
    if (L <= m) update(L, R, i, lson);
    if (R > m) update(L, R, i, rson);
}

int query(int x, int l, int r, int rt)
{
    if (cover[rt] >= 0)
        return cover[rt];
    int m = (l + r) >> 1;
//    pushdown(rt);
    if (cover[rt] != -1)
    cover[rt << 1] = cover[rt << 1 | 1] = cover[rt], cover[rt] = -1;
    if (x <= m) return query(x, lson);
    else return query(x, rson);
}

void solve()
{
//    CLR(cover, -1);///!!!
    sort(g, g + n + 1);
    FD(i, n, 0)
    {
        if (g[i].y1 == g[i].y2)
            f[i] = i;
        else
        {
            int k = query(g[i].x1, 0, N, 1);
            f[i] = f[k];
            if (g[k].y1 == g[k].y2)
                ansx[i] = g[i].x1;///!!!
            else
                ansx[i] = ansx[k];
        }
        int L = g[i].x1, R = g[i].x2;
        if (L > R) swap(L, R);
        update(L, R, i, 0, N, 1);
    }
}

void fun(int x)
{
    int k = query(x, 0, N, 1);
    if (g[k].y1 != g[k].y2) x = ansx[k];///!!!
    if (f[k] == n) printf("%d\n", x);
    else printf("%d %d\n", x, g[f[k]].y1);
}

int main()
{
    int x;
    while (~scanf("%d%d", &n, &m))
    {
        REP(i, n)
        {
            scanf("%d%d%d%d", &g[i].x1, &g[i].y1, &g[i].x2, &g[i].y2);
            if (g[i].y1 < g[i].y2) swap(g[i].x1, g[i].x2), swap(g[i].y1, g[i].y2);
        }
        g[n].x1 = 0; g[n].y1 = N + 1; g[n].x2 = N; g[n].y2 = N + 1;
        solve();
        while (m--)
        {
            scanf("%d", &x);
            fun(x);
        }
    }
    return 0;
}
