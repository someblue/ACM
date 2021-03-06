/*
* this code is made by WJMKQDM
* Problem: 1154
* Verdict: Accepted
* Submission Date: 2014-07-23 00:09:56
* Time: 168MS
* Memory: 1672KB
*/
#include <bits/stdc++.h>
using namespace std;
 
inline int lowbit(const int x) { return x & -x; }
typedef long long LL;
const int N = 33;
LL preSum[N], temp[N];
 
void Prepare() {
    preSum[0] = temp[0] = 1;
    for (int i = 1; i < N; ++i) {
        preSum[i] = temp[i - 1] + (1LL << i);
        temp[i] = temp[i - 1] + preSum[i];
    }
}
 
int main() {
    //for (int i = 1; i <= 128; ++i) { cout << i << ' ' << lowbit(i) << endl; }
    int n;
    Prepare();
    while (cin >> n) {
        LL answer = 0;
        for (int i = 0; i < N; ++i) {
            if (n & (1LL << i)) {
                answer += preSum[i];
            }
        }
        cout << answer << endl;
    }
    return 0;
}