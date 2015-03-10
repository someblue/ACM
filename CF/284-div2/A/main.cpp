#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int n,x;
pii p[55];

void run()
{
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].first, &p[i].second);
    int ans = 0;
    int now = 1;
    int pos = 0;
    while(true)
    {
        if(now+x>p[pos].first)
        {
            ans += p[pos].second - now + 1;
            now = p[pos].second + 1;
            pos++;
        }
        else now+=x;
        if(pos>=n) break;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&x)!=EOF)
        run();
    return 0;
}
