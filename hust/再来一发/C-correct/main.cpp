#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

#define mp make_pair
typedef pair<int,int> PII;
typedef long long lld;
const int N = 101000;

int n,m,ch[2][N][2],tot,cnt[N<<1];
lld ans = 0;
map<PII,int> Map;
int dfs(int u) {
        if (u==-1) return -1;
        int a = dfs(ch[0][u][0]);
        int b = dfs(ch[0][u][1]);
        int x;
        if (Map.find(mp(a,b))==Map.end()) {
                Map[mp(a,b)] = x = tot ++;
        } else {
                x = Map[mp(a,b)];
        }
        cnt[x] ++;
        return x;
}
int DFS(int u) {
        if (u==-1) return -1;
        int a = DFS(ch[1][u][0]);
        int b = DFS(ch[1][u][1]);
        int x;
        if (Map.find(mp(a,b))==Map.end()) {
                Map[mp(a,b)] = x = tot ++;
        } else {
                x = Map[mp(a,b)];
                ans += cnt[x];
        }
        return x;
}
lld work() {
        for (int i = 0; i <= n+m; i ++) cnt[i] = 0;
        tot = 0;
        Map.clear();
        Map[mp(-1,-1)] = tot ++;
        dfs(1);
        ans = 0;
        DFS(1);
        return ans;
}

int main() {
        int cas;
        scanf("%d",&cas);
        while (cas--) {
                scanf("%d%d",&n,&m);
                for (int i = 1; i <= n; i ++) {
                        scanf("%d%d",&ch[0][i][0],&ch[0][i][1]);
                }
                for (int i = 1; i <= m; i ++) {
                        scanf("%d%d",&ch[1][i][0],&ch[1][i][1]);
                }
                printf("%I64d\n",work());
        }
        return 0;
}
