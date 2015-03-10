#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

set<pii> s[2];
int n,xx,yy,x,y,dx,dy,t;

void run()
{
    s[0].clear();
    s[1].clear();
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        dx=xx-x;
        dy=yy-y;
        t = (dx*dy>=0?1:0);
        if(dx<0) dx=-dx;
        if(dy<0) dy=-dy;
        int g = __gcd(dx,dy);
        dx/=g;
        dy/=g;
        s[t].insert(make_pair(dx,dy));
    }
    cout << s[0].size() + s[1].size() << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(cin>>n>>xx>>yy)
        run();
    return 0;
}
