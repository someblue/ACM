#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-8;
const int N = 1010;
int cas = 1;

double h[N],ans;
int n;

bool solve()
{
    for(int i=3;i<=n;i++)
    {
        h[i]=2*h[i-1]-h[i-2]+2;
        if(h[i]<0)
            return 0;
    }
    return 1;
}

void bs()
{
    double l,r;
    l=0.0;
    r=h[1];
    while(r-l>eps)
    {
        h[2] = (l+r)/2.0;
        if(solve())
        {
            r=h[2];
            ans = min(ans,h[n]);
        }
        else
            l=h[2];
    }
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    cin>>n>>h[1];
    ans = 2e9;
    bs();
    printf("%.2lf\n",ans);
    return 0;
}
