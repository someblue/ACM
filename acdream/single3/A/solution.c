/*
* this code is made by WJMKQDM
* Problem: 1152
* Verdict: Accepted
* Submission Date: 2014-07-23 00:38:46
* Time: 3620MS
* Memory: 25980KB
*/
#include <bits/stdc++.h>
using namespace std;

inline int Lowbit(const int x) { return x & -x; }
typedef long long LL;
const int N = 111111;
const int M = 55;

struct BIT {
    int a[N][M];
    int n, m;
    void Clear(int _n) {
        n = _n + 2;
        m = M;
        for (int i = 0; i <= n; ++i) {
            memset(a[i], 0, sizeof a[i]);
        }
    }
    void Add(int x, int y, int d) {
        for (int i = x; i < n; i += Lowbit(i)) {
            for (int j = y; j < m; j += Lowbit(j)) {
                a[i][j] += d;
            }
        }
    }
    int Sum(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= Lowbit(i)) {
            for (int j = y; j > 0; j -= Lowbit(j)) {
                sum += a[i][j];
            }
        }
        return sum;
    }
} bit;

inline int Query(int x, int y) {
    return bit.Sum(x - 1, bit.m - 1) + bit.Sum(bit.n - 1, y - 1) - bit.Sum(x - 1, y) - bit.Sum(x, y - 1);
}

int a[N];
int Run() {
    int n, m, x, y;
    while (~scanf("%d", &n)) {
        bit.Clear(n);
        LL answer = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            a[i] = x;
            answer += Query(i, x);
            bit.Add(i, x, 1);
        }
        printf("%lld\n", answer);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            answer -= Query(x, a[x]);
            bit.Add(x, a[x], -1);
            answer -= Query(y, a[y]);
            bit.Add(y, a[y], -1);
            swap(a[x], a[y]);
            answer += Query(x, a[x]);
            bit.Add(x, a[x], 1);
            answer += Query(y, a[y]);
            bit.Add(y, a[y], 1);
            printf("%lld\n", answer);
        }
    }
    return 0;
}

int main() {
    //ios::sync_with_stdio(0);
    return Run();
}
