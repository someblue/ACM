#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

int w[N][10];
pii que[10][N];
int l[10], r[10], ans[10], ans2[10], anslen;
int n,m,k;

void update(int l)
{
    if(l <= anslen) return;
    anslen = l;
    for(int i=1; i<=m; i++)
        ans[i] = ans2[i];
}

void push(int mm, int idx, int num)
{

}

void pop(int mm, int idx)
{

}

bool judge(int len)
{
    for(int i=1; i<=m; i++)
        l[i] = r[i] = 0;

}

void bs(int l, int r)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(judge(mid))
        {
            update(mid);
            l = mid+1;
        } else r = mid-1;
    }
}

void run()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&w[i][j]);
    for(int i=1; i<=m; i++)
        ans[i] = 0;
    anslen = 0;
    bs(1,n);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d%d%d",&n,&m,&k))
        run();
    return 0;
}
