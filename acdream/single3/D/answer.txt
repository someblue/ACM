/*
* this code is made by WJMKQDM
* Problem: 1155
* Verdict: Accepted
* Submission Date: 2014-07-23 00:58:19
* Time: 684MS
* Memory: 7100KB
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 222222;
inline int idx(char x) { return (int) x; }

struct SA {
    char s[N];
    int sa[N], t1[N], t2[N], c[N];
    int ht[N], rk[N], n;
    void Cal(int m = 256) {
        n = strlen(s);
        //cout << s << endl;
        int *x = t1, *y = t2;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[i] = idx(s[i])]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;
            for (int i = n - k; i < n; i++) y[p++] = i;
            for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
            for (int i = 0; i < m; i++) c[i] = 0;
            for (int i = 0; i < n; i++) c[x[y[i]]]++;
            for (int i = 1; i < m; i++) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n) break;
            m = p;
        }
        for (int i = 0; i < n; i++) rk[sa[i]] = i;
        for (int i = 0, k = 0; i < n; i++) {
            if (k) k--;
            int j = sa[rk[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            ht[rk[i]] = k;
        }
        //for (int i = 0; i < n; i++) cout << i << ' ' << ht[i] << ' ' << sa[i] << ' ' << s + sa[i] << endl;
    }
} sa;

int Run() {
    while (~scanf("%s", sa.s)) {
        int len = strlen(sa.s);
        strcat(sa.s, "$");
        scanf("%s", sa.s + len + 1);
        sa.Cal();
        long long answer = 0;
        for (int i = 2; i <= sa.n - 1; ++i) {
            if ((sa.sa[i - 1] <= len) ^ (sa.sa[i] <= len)) {
                int l, r;
                if (i == sa.n - 1) {
                    r = 0;
                } else {
                    r = sa.ht[i + 1];
                }
                if (i == 2) {
                    l = 0;
                } else {
                    l = sa.ht[i - 1];
                }
                //cout << l << ' ' << r << ' ' << sa.ht[i] << endl;
                answer += max(0, sa.ht[i] - max(l, r));
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    //ios::sync_with_stdio(0);
    return Run();
}
