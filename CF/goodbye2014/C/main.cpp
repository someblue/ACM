#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

int w[N],b[N],n,m;
int stk[N],p[N];

void run()
{
    for(int i=1; i<=n; i++) scanf("%d",w+i);
    for(int i=1; i<=m; i++) scanf("%d",b+i);
    int ans = 0;
    int num = 0;
    int pos;
    memset(p,-1,sizeof(p));
    for(int d=1;d<=m;d++)
    {
        int book = b[d];
        if(p[book]==-1) pos = num, num++;
        else pos = p[book]-1;
        for(int k=pos; k>=1; k--) ans+=w[stk[k]],p[stk[k]]=k+1,stk[k+1]=stk[k];
        stk[1]=book, p[book]=1;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
