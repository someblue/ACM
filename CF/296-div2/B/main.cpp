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
const int N = 200010;
int cas = 1;

int p[30][30];
int n;
char s1[N], s2[N];

void run()
{
    cin>>s1>>s2;
    int i,j,k;
    rep(i,0,26) rep(j,0,26) p[i][j]=-1;
    int cnt = 0;
    rep(i,0,n) if(s1[i]!=s2[i]) {
        cnt++;
        p[s1[i]-'a'][s2[i]-'a'] = i+1;
    }
    rep(i,0,26) rep(j,0,26) {
        if(p[i][j]!=-1 && p[j][i]!=-1) {
            printf("%d\n",cnt-2);
            printf("%d %d\n", p[i][j], p[j][i]);
            return;
        }
    }
    rep(i,0,26) rep(j,0,26) rep(k,0,26) {
        if(p[i][j]!=-1 && p[k][i]!=-1) {
            printf("%d\n", cnt-1);
            printf("%d %d\n", p[i][j], p[k][i]);
            return;
        }
    }
    printf("%d\n-1 -1\n", cnt);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>n)
        run();
    return 0;
}
