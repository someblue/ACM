#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int n,t;
int x[N];

void run()
{
    for(int i=1;i<n;i++) scanf("%d",x+i);
    int now = 1;
    while(now < t)
    {
        now += x[now];
    }
    if(now == t) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&t)!=EOF)
        run();
    return 0;
}
