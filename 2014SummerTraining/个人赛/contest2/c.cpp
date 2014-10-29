/*
* this code is made by scaucontest
* Problem: 1149
* Verdict: Accepted
* Submission Date: 2014-07-17 11:13:11
* Time: 488MS
* Memory: 1676KB
*/
#include <bits/stdc++.h>
using namespace std;
  
const int MAXN = 24;
const int MAXM = 10000000;
int a[MAXN];
inline int cmp(const int a, const int b) { return a > b; }
  
int main() {
    int n, m;
    while (~scanf("%d", &n)) {
        assert(n <= MAXN);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            assert(a[i] <= MAXM);
        }
        scanf("%d", &m);
        assert(m <= MAXM);
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (m >= a[i]) {
                m -= a[i];
            }
        }
        cout << (m ? "NO" : "YES") << endl;
    }
    return 0;
}