#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
const int M = 10;
int cas = 1;

struct RMQ{
    int d[N][32];
    int n;
    void init(int *a, int sz)
    {
        n = sz;
        for(int i=0; i<n; i++) d[i][0]=a[i];
        for(int j=1; (1<<j)<=n; j++)
            for(int i=0; i+(1<<j)-1<n; i++)
                d[i][j]=(d[i][j-1]> d[i+(1<<(j-1))][j-1]? d[i][j-1]: d[i+(1<<(j-1))][j-1]);
    }
    int query(int L, int R)
    {
        int k=0;
        while((1<<(k+1))<=R-L+1) k++;
        return (d[L][k]> d[R-(1<<k)+1][k]? d[L][k]: d[R-(1<<k)+1][k]);
    }
}rmq[M];

int n,m,k;
int w[M][N];
int ans[M],len;

void run()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&w[j][i]);
    for(int i=0; i<m; i++)
        rmq[i].init(w[i], n);
    for(int i=0; i<m; i++)
        ans[i]=0;
    len=0;
    int l, r;
    l=r=0;
    for(r=0; r<n; r++)
    {
        while(l<=r)
        {
            int sum=0;
            for(int i=0; i<m; i++)
                sum+=rmq[i].query(l,r);
            if(sum>k) l++;
            else break;
        }
//        cout << l << ' ' << r << endl;
        if(l<=r && r-l+1 > len)
        {
            len = r-l+1;
            for(int i=0; i<m; i++)
                ans[i] = rmq[i].query(l,r);
        }
    }
    for(int i=0; i<m; i++)
        printf("%d ",ans[i]);
    puts("");
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
