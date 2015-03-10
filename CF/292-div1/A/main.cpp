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
const int N = 20;
int cas = 1;

int n, cnt[N];
char s[N];
char table[][10] = {"","","2","3","22","5","23","7","222","33","25"};

inline bool cmp(const char& a, const char& b) {
    return a>b;
}

void add_cnt(int x) {
    switch(x) {
        case 9: cnt[3]+=2;
        case 8: cnt[2]+=3;
        case 7: cnt[7]++;
        case 6: cnt[2]++; cnt[3]++;
        case 5: cnt[5]++;
        case 4: cnt[2]+=2;
        case 3: cnt[3]++;
        case 2: cnt[2]++;
    }
}

void run()
{
    MS(cnt);
    int i,k;
    rep(i,0,n)
        add_cnt(s[i]-'0');

    k=7;
    rep(i,0,cnt[k]) putchar(k+'0');
    cnt[2] -= 4*cnt[k];
    cnt[3] -= 2*cnt[k];
    cnt[5] -= 1*cnt[k];

    k=5;
    rep(i,0,cnt[k]) putchar(k+'0');
    cnt[2] -= 3*cnt[k];
    cnt[3] -= 1*cnt[k];

    k=3;
    rep(i,0,cnt[k]) putchar(k+'0');
    cnt[2] -= 1*cnt[k];

    k=2;
    rep(i,0,cnt[k]) putchar(k+'0');

    puts("");
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin >> n >> s)
        run();
    return 0;
}
