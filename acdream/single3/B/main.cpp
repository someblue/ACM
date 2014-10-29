#include <bits/stdc++.h>
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,n) for(i=1;i<=(n);++i)
#define N 10005
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = 1<<30;
const double eps = 0.000001;

VI fac[N];
int cnt[N];

void make_fac()
{
    int i,j;
    for(i=1;i<N;++i)
        for(j=i;j<N;j+=i)
            fac[j].push_back(i);
}

void run()
{
    int n,k,i,j,a;
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i)
    {
        scanf("%d",&a);
        for(j=0;j<fac[a].size();++j)
            ++cnt[fac[a][j]];
    }
    for(i=N-1;i>=1;--i)
    if(cnt[i]>=k)   {printf("%d\n",i);return;}
    puts("1");
}

int main()
{
    make_fac();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
