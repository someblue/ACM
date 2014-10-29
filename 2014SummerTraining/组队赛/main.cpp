#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

const int N = 50010;

map <int, int> mp;
int dp[N], t[N], a[N];
int n;

int findt (int x) {
    int f = 0, e = n + 1;
    while (f + 1 < e) {
        int mid = f + e >> 1;
        if (t[mid] <= x) e = mid;
        else f = mid;
    }
    return e;
}

int main()
{
    while (~scanf ("%d", &n)) {
        mp.clear();
        int an = 0, b;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &b);
            if (b != a[an]) a[++an] = b;
        }
        memset (t, 0, sizeof (int) * (n));
        n = an;
        int f;
        int sn = sqrt (n);
        for (int i = 1; i <= n; i++) {
            if (mp.find(a[i]) == mp.end()) f = 0; else f = mp[a[i]];
            int ft = findt (f);
            if (f == 0) f = ft; else f = ft - 1;
            f = min (f, sn);

            for (int j = f; j >= 2; j--) {
                t[j] = t[j - 1];
            }
            t[1] = i;
            mp[a[i]] = i;

            dp[i] = i;
            for (int k = 1; k * k < i; k++) {
                int j = t[k];
                dp[i] = min (dp[i], dp[j - 1] + k * k);
            }
        }
        printf ("%d\n", dp[n]);
    }
}
