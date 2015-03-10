#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1000;
int cas = 1;

ll x1,y1,x2,y2;
ll a,b,c;

void run()
{
    scanf("%I64d%I64d",&x2,&y2);
    int ans = 0;
    ll c1,c2;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
//        c1 = a*x1+b*y1;
//        c2 = a*x2+b*y2;
//        if(c1>c&&c2<c || c1<c&&c2>c) ans++;
        c1 = a*x1+b*y1+c;
        c2 = a*x2+b*y2+c;
        if(c1<0 ^ c2<0) ans++;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%I64d%I64d",&x1,&y1)!=EOF)
        run();
    return 0;
}
