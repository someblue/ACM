#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 3010;
int cas = 1;

int n;
int p[N];

void run()
{
    int i, j, cnt=0;
    rep(i, 0, n) scanf("%d", p+i);
    rep(i, 0, n) rep(j, i+1, n) if(p[i] > p[j]) cnt++;
    if(cnt%2==0) printf("%.6f\n", (double)2*cnt);
    else printf("%.6f\n", (double)2*cnt-1);
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d",&n))
        run();
    return 0;
}
