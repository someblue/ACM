#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,id[N],a[N],sta[N][N],in[N],dp[N],vis[N];
vector<int> G[N];
int topo() {
    memset(dp,0,sizeof(dp));
    queue<int> que;
    int res=0;
    bool empty = 1;
    for(int i=0; i<m; i++) {
        if(vis[i]==n) empty=0;
        if(!in[i]) que.push(i);
    }
    while(!que.empty()) {
        int u=que.front();
        que.pop();
        if(res<dp[u]) res=dp[u];
        for(unsigned i=0; i<G[u].size(); i++) {
            if(dp[G[u][i]] < dp[u]+1)
                dp[G[u][i]] = dp[u]+1;
            in[G[u][i]]--;
            if(!in[G[u][i]]) que.push(G[u][i]);
        }
    }
    return empty?0:res+1;
}
int main() {
    freopen("case.txt","r",stdin);
    while(~scanf("%d%d", &n, &m)) {
        map<int, int> mp;
        memset(sta,0,sizeof(sta));
        memset(in,0,sizeof(in));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++) G[i].clear();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) scanf("%d", a+j);
            if(i==0) {
                for(int j=0; j<m; j++) mp[a[j]] = j;
            }
            for(int j=0; j<m; j++) {
                if(mp.count(a[j])) id[j]=mp[a[j]], vis[id[j]]++;
                else id[j] = -1;
            }
            for(int j=0; j<m; j++)
                for(int k=j+1; k<m; k++)
                    if(id[j]!=-1 && id[k]!=-1)
                        sta[id[j]][id[k]]++;
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
                if(sta[i][j]==n)
                    G[i].push_back(j), in[j]++;
        printf("%d\n", topo());
    }
    return 0;
}
