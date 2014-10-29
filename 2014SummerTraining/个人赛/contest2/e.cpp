/*
* this code is made by scaucontest
* Problem: 1151
* Verdict: Accepted
* Submission Date: 2014-07-17 17:06:13
* Time: 1244MS
* Memory: 14872KB
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> Array;
typedef long long LL;
const int MOD = 20140717;
const int MAXN = 1123456;
Array modFac;
 
void GetFactor(int n, Array &arr) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i) {
            continue;
        }
        while (n % i == 0) {
            arr.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        arr.push_back(n);
    }
    //for (int i = 0; i < arr.size(); ++i) { cout << i << ' ' << arr[i] << endl; }
}
 
int d[MAXN], x[MAXN], y[MAXN];
 
void Set(int n) {
    for (int i = 0; i < n; ++i) {
        ++d[x[i]];
        --d[y[i] + 1];
    }
}
 
void Reset(int n) {
    for (int i = 0; i < n; ++i) {
        --d[x[i]];
        ++d[y[i] + 1];
    }
}
 
vector<Array> fac, inv;
 
void GCD(const LL &a, const LL &b, LL &x, LL &y, LL &d) {
    if (b) {
        GCD(b, a % b, y, x, d);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
        d = a;
    }
}
 
int Inverse(int a, int mod) {
    int p = mod - 2, result = 1;
    a %= mod;
    while (p > 0) {
        if (p & 1) {
            result *= a;
            result %= mod;
        }
        a *= a;
        a %= mod;
        p >>= 1;
    }
    return result;
}
 
int Combination(const int n, const int m, const int id) {
    if (m == 0 || n == m) {
        return 1;
    }
    if (n == 0 || m > n) {
        return 0;
    }
    int &mod = modFac[id];
    if (n >= mod) {
        return Combination(n % mod, m % mod, id) * Combination(n / mod, m / mod, id) % mod;
    } else {
        return fac[id][n] * (inv[id][m] * inv[id][n - m] % mod) % mod;
    }
}
 
int Solve(const int n, const int id) {
    int sum = d[0], ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum += d[i];
        //cout << sum << ' ' << i << endl;
        ans += Combination(sum, i, id);
        if (ans >= modFac[id]) {
            ans -= modFac[id];
        }
    }
    return ans;
}
 
int CRT(const Array &ans, const Array &mod) {
    int result = *ans.rbegin(), multi = *mod.rbegin();
    for (int i = ans.size() - 2; i >= 0; --i) {
        while (result % mod[i] != ans[i]) {
            result += multi;
        }
        multi *= mod[i];
    }
    return result % MOD;
}
 
int Solve(const int n) {
    Array modAns(modFac.size());
    for (int i = 0; i < modFac.size(); ++i) {
        modAns[i] = Solve(n, i);
        //cout << modFac[i] << ' ' << modAns[i] << endl;
    }
    return CRT(modAns, modFac);
}
 
void Prepare(const Array &f) {
    fac.clear();
    fac.resize(f.size());
    inv.clear();
    inv.resize(f.size());
    for (int i = 0; i < f.size(); ++i) {
        fac[i].resize(f[i] + 1);
        inv[i].resize(f[i] + 1);
        for (int j = fac[i][0] = 1; j < f[i]; ++j) {
            fac[i][j] = fac[i][j - 1] * j;
            fac[i][j] %= f[i];
            inv[i][j] = Inverse(fac[i][j], f[i]);
        }
    }
}
 
const int N = 55;
int c[N][N];
 
void Test() {
    c[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            Array ans;
            for (int k = 0; k < modFac.size(); ++k) {
                ans.push_back(Combination(i, j, k));
            }
            if (CRT(ans, modFac) != c[i][j]) {
                cout << i << ' ' << j << ' ' << CRT(ans, modFac) << ' ' << c[i][j] << endl;
                for (int i = 0; i < 3; ++i) {
                    cout << ans[i] << endl;
                }
                return ;
            }
        }
    }
    cout << "Checked" << endl;
}
 
int Run() {
    GetFactor(MOD, modFac);
    Prepare(modFac);
    //Test();
    //cout << Combination(10, 5, 0) << endl; // 6
    //cout << Combination(10, 5, 1) << endl; // 38
    int n;
    //memset(d, 0, sizeof d);
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", x + i, y + i);
            if (x[i] > y[i]) {
                swap(x[i], y[i]);
            }
            x[i] = max(0, x[i]);
            y[i] = min(n, y[i]);
        }
        Set(n);
        printf("%d\n", Solve(n));
        Reset(n);
    }
    return 0;
}
 
int main() {
    //freopen("e.in", "r", stdin);
    //freopen("e.cmp", "w", stdout);
    //ios::sync_with_stdio(0);
    return Run();
}