#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>
#define FOR(i,n) for(i=1;i<=(n);i++)
#define X a[i]
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 50010;
int cas = 1;

int a[N],n,cnt;
int t[500],pos[N];
int dp[N];

inline bool cmp(int a,int b)
{
    return a>b;
}

void run()
{
    map<int,int> mp;
    int i,j,k;
    int an = 0 , x;
    cnt=0;
    dp[0]=0;
    a[0]=-1;
    FOR(i,n)
    {
        scanf("%d",&x);
        if(x!=a[an]) a[++an]=x;
    }
    n = an;
    FOR(i,n)
    {
        if(mp.find(X)==mp.end())
            mp[X]=cnt++;
        X = mp[X];
        dp[i] = i;
    }
    int sn = sqrt(n);
    FOR(i,n) cout<<a[i]<<' ';
    cout<<endl;
    memset(pos,0,sizeof(pos));
    memset(t,0,sizeof(t));
    FOR(i,n)
    {
        cout<<i<<": ";
        if(a[i]!=a[i-1])
        {
            k = lower_bound(t+1,t+500,pos[X],cmp) - t;
            k = min(k,sn);


            for(j=k;j>=2;j--)   t[j]=t[j-1];
            t[1]=i;
        }
        for(j=1;j<=10;j++) cout<<t[j]<<' ';
        cout<<endl;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
