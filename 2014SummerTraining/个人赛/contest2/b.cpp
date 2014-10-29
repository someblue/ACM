/*
* this code is made by scaucontest
* Problem: 1148
* Verdict: Accepted
* Submission Date: 2014-07-17 14:23:13
* Time: 2052MS
* Memory: 2848KB
*/
//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
typedef long  long LL;
 
const int N = 100005;
const int M = 1000005;
const int inf = 1 << 28;
const int mod = 1e9 + 7;
const double eps = 1e-8;
using namespace std;
int mob[N];
LL sum[N];
 
void Mobuis() {
    memset(mob, 0, sizeof(mob));
    int n = N - 5;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) mob[i] = 2;
        if (mob[i]) continue;
        mob[i] = i;
        if (i >= 400) continue;
        for (int j = i * i; j <= n; j += i) mob[j] = i;
    }
    mob[1] = 1, sum[1] = 1;
    for (int i = 2; i <= n; i++) {
        if ((i / mob[i]) % mob[i] == 0) mob[i] = 0;
        else mob[i] = -mob[i / mob[i]];
    }
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + mob[i] * i;
        mob[i] += mob[i - 1];
    }
}
 
LL cal(int x, int y) {
    return 1LL * (x + y) * (y - x + 1) >> 1;
}
 
LL solve(int n, int m, LL &ansx, LL &ansy) {
    LL res = 0;
    ansx = ansy = 0;
    for (int i = n; i > 0; ) {
        int x = n / i, y = m / i;
        int tmp = max(n / (x + 1), m / (y + 1));
        res += 1LL * (mob[i] - mob[tmp]) * x * y;
        ansx += 1LL * (sum[i] - sum[tmp]) * y *  cal(1, x);
        ansy += 1LL * (sum[i] - sum[tmp]) * x * cal(1, y);
        i = tmp;
    }
    return res;
}
 
int main() {
    Mobuis();
    int n, m;
    while (cin >> n >> m) {
        LL res, resx, resy;
        if (n > m) res = solve(m, n, resy, resx);
        else res = solve(n, m, resx, resy);
        cout << res << " " << resx << " " << resy << endl;
    }
    return 0;
}