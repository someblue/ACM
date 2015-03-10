#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 300002;
int cas = 1;

int input[N][3], n, ans[N];

inline int readint() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x*10 + c -'0';
        c = getchar();
    }
    return x;
}
//
//inline void writeint(int i) {
//    int p = 0;
//    if(i==0) p++;
//    else while(i) {
//        buf[p++] = i%10;
//        i/=10;
//    }
//}

int col[N<<2];
int sum[N<<2];
int val[N<<2];

void pushup(int rt) {
    // sum[rt] = sum[rt<<1] + sum[rt<<1|1];

    if(val[rt<<1] == val[rt<<1|1])
        val[rt] = val[rt<<1];
}
void pushdown(int rt) {
    // if(col[rt]) {
    //     col[rt<<1] = col[rt<<1|1] = col[rt];
    //     sum[rt<<1] = (m-(m>>1)) * col[rt];
    //     sum[rt<<1|1] = (m>>1) * col[rt];
    //     col[rt] = 0;
    // }

    if(col[rt]) {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        val[rt<<1] = val[rt<<1|1] = col[rt];
        col[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    // sum[rt] = 1;
    val[rt] = 0;
    if(l==r) return;
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <=l && r <= R) {
        col[rt] = c;
        // sum[rt] = c * (r-l+1);
        val[rt] = c;
        return;
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    if(L<=m) update(L, R, c, lson);
    if(R>m)  update(L, R, c, rson);
    pushup(rt);
}

void show_ans(int l, int r, int rt) {
    if(l==r) {
        if(l!=1) printf(" ");
        printf("%d", val[rt]);
        return;
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    show_ans(lson);
    show_ans(rson);
}

int m;
void run()
{
    MS(ans);
    int i;
    rep(i, 0, m) {
        input[i][0] = readint();
        input[i][1] = readint();
        input[i][2] = readint();
    }
    build(1, n, 1);
    per(i, 0, m) {
        if(input[i][0] < input[i][2])
            update(input[i][0], input[i][2]-1, input[i][2], 1, n, 1);
        if(input[i][1] > input[i][2])
            update(input[i][2]+1, input[i][1], input[i][2], 1, n, 1);
    }
    show_ans(1,n,1);
    puts("");
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d%d", &n, &m))
        run();
    return 0;
}
