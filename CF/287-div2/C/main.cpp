#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 55;
int cas = 1;

ll pow2[N];

void pre()
{
    pow2[0] = 1;
    for(int i=1; i<N; i++)
        pow2[i] = 2*pow2[i-1];
}

ll dfs(int level, int command, ll pos)
{
    if(level == 0) return 1;
    int lr = (pos<=pow2[level]/2)? 0:1;
//    if(lr==0) cout << "left" << endl;
//    else cout << "right" << endl;
    ll tmp;
    if(lr == command)
        tmp = 1;
    else
        tmp = pow2[level];
//    cout << tmp << endl;
    return tmp + dfs(level-1, lr^1, lr==0? pos: pos-pow2[level]/2);
}

ll h, n;

void run()
{
    cout << dfs(h, 0, n) - 1 << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    pre();
    while(cin >> h >> n)
        run();
    return 0;
}
