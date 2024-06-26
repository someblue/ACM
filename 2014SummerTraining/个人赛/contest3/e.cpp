/*
* this code is made by WJMKQDM
* Problem: 1156
* Verdict: Accepted
* Submission Date: 2014-07-23 03:04:52
* Time: 36MS
* Memory: 1676KB
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
inline LL PreSum(const LL &n) { return n * (n + 1) >> 1; }
 
int main() {
    int n;
    while (~scanf("%d", &n)) {
        LL answer = 0;
        while (n > 10) {
            int p = n / 10;
            answer += PreSum(p - 1) * 9;
            int r = n % 10;
            answer += (LL) p * r;
            n /= 10;
        }
        printf("%lld\n", answer);
    }
    return 0;
}