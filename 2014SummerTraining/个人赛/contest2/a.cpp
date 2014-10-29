/*
* this code is made by scaucontest
* Problem: 1147
* Verdict: Accepted
* Submission Date: 2014-07-17 11:12:14
* Time: 220MS
* Memory: 1676KB
*/
#include <bits/stdc++.h>
using namespace std;
  
typedef long long LL;
  
LL dfs(const LL &len, const LL &s, const LL &pos, const LL &dist) {
    if (len == 1) {
        return s;
    }
    LL lenR = len >> 1;
    LL lenL = len - lenR;
    if (pos <= lenL) { // to left
        return dfs(lenL, s, pos, dist << 1);
    } else { // to right
        return dfs(lenR, s + dist, pos - lenL, dist << 1);
    }
}
  
LL dfs(const LL &len, const LL &s, const LL &num, const LL &dist, const LL &pos) {
    if (len == 1) {
        return pos;
    }
    LL nth = (num - s) / dist + 1;
    LL lenR = len >> 1;
    LL lenL = len - lenR;
    if (nth & 1) { // to left
        return dfs(lenL, s, num, dist << 1, pos);
    } else { // to right
        return dfs(lenR, s + dist, num, dist << 1, pos + lenL);
    }
}
  
int Run() {
    LL n, m;
    //while (cin >> n >> m) {
    while (~scanf("%lld%lld", &n, &m)) {
        LL x, y;
        for (int i = 0; i < m; ++i) {
            //cin >> x >> y;
            scanf("%lld%lld", &x, &y);
            if (x == 1) {
                //cout << dfs(n, 1, y, 1) << endl;
                printf("%lld\n", dfs(n, 1, y, 1));
            } else {
                //cout << dfs(n, 1, y, 1, 1) << endl;
                printf("%lld\n", dfs(n, 1, y, 1, 1));
            }
        }
    }
    return 0;
}
  
int main() {
    //ios::sync_with_stdio(0);
    return Run();
}