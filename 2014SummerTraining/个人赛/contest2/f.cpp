/*
* this code is made by khd
* Problem: 1055
* Verdict: Accepted
* Submission Date: 2014-07-17 21:25:16
* Time: 504MS
* Memory: 14944KB
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
 
const int N = 2e5 + 5;
int n, m;
 
struct BIT {
    int bit[N];
    void init() {
        memset(bit, 0, sizeof (bit));
    }
    int lowbit(int x) {
        return x&(-x);
    }
    void update(int x, int key) {
        if (!x) return;
        for (int i = x; i <= m; i += lowbit(i)) bit[i] += key;
    }
    int query(int x) {
        if (!x) return 0;
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) res += bit[i];
        return res;
    }
}lb, rb;
 
int L[N], R[N], x[N], pos[N], type[N], pc;
map<int, int>mp;
 
int main() {
    while (cin >> n) {
        char key[10];
        m = pc = 0;
        memset(type, 0, sizeof (type));
        for (int i = 1; i <= n; i++) {
            scanf("%s%d", key, &L[i]);
            if (key[0] == 'C') {
                type[i] = 2;
                continue;
            }
            scanf("%d", &R[i]);
            x[m++] = L[i];
            x[m++] = R[i];
            if (key[0] == 'D') {
                pos[++pc] = i;
                type[i] = 1;
            }
        }
        sort(x, x + m);
        m = unique(x, x + m) - x;
        mp.clear();
        for (int i = 0; i < m; i++) mp[x[i]] = i + 1;
        lb.init();
        rb.init();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (type[i] == 1) {
                sum++;
                lb.update(mp[R[i]], 1);
                rb.update(m - mp[L[i]] + 1, 1);
            }
            else if (type[i] == 0) {
                printf("%d\n", sum - rb.query(m - mp[R[i]]) - lb.query(mp[L[i]] - 1));
            }
            else {
                int p = pos[L[i]];
                sum--;
                lb.update(mp[R[p]], -1);
                rb.update(m - mp[L[p]] + 1, -1);
            }
        }
    }
    return 0;
}