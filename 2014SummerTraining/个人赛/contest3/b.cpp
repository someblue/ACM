/*
* this code is made by WJMKQDM
* Problem: 1153
* Verdict: Accepted
* Submission Date: 2014-07-23 02:40:32
* Time: 188MS
* Memory: 3316KB
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1 << 14;
vector<int> fac[N];
int answer[N];
 
int main() {
    for (int i = 0; i < N; ++i) {
        fac[i].clear();
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            fac[j].push_back(i);
        }
    }
    int T, n, x, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        memset(answer, 0, sizeof answer);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            for (int j = 0; j < fac[x].size(); ++j) {
                ++answer[fac[x][j]];
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            if (answer[i] >= k) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}