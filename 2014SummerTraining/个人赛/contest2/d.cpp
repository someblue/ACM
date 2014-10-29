/*
* this code is made by khd
* Problem: 1150
* Verdict: Accepted
* Submission Date: 2014-07-18 20:31:09
* Time: 1548MS
* Memory: 49240KB
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 2014;
 
int K;
 
void GetNext(int *a, int nxt[][N], int n) {
    int pre[N];
    for (int i = 1; i <= K; i++) nxt[n + 1][i] = pre[i] = n + 1;
    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= K; j++) nxt[i][j] = pre[j];
        pre[a[i]] = i;
    }
}
 
int nxt1[N][N], nxt2[N][N];
int a[N], b[N], n, m;
int dp[N][N];
int num1[N], num2[N];
 
int main() {
    //freopen("in", "r", stdin);
    while (cin >> K) {
        cin >> n;
        memset(num1, 0, sizeof (num1));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            num1[a[i]]++;
        }
        cin >> m;
        memset(num2, 0, sizeof (num2));
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            num2[b[i]]++;
        }
        GetNext(a, nxt1, n);
        GetNext(b, nxt2, m);
        int nm = 10086;
        for (int i = 1; i <= K; i++) nm = min(nm, max(num1[i], num2[i]) + 1);
        memset(dp, -1, sizeof (dp));
        dp[0][0] = 0;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= nm; j++) {
                if (dp[i][j] == -1) continue;
                for (int k = 1; k <= K; k++) {
                    if (dp[nxt1[i][k]][j + 1] < nxt2[dp[i][j]][k]) {
                        dp[nxt1[i][k]][j + 1] = nxt2[dp[i][j]][k];
                    }
                }
            }
        }
        for (int i = 1; i <= nm; i++) {
            if (dp[n + 1][i] == m + 1) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}