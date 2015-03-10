#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 10000010;
int cas = 1;

int pri[N],sum[10][N];
int mx = 0;
void pre()
{
    pri[0]=pri[1]=0;
    for(int i=2;i<N;i++)
    {
        if(pri[i]) continue;
        for(int j=i;j<N;j+=i)
            pri[j]++;
    }
    for(int i=2;i<N;i++)
    {
        for(int j=0;j<10;j++)
            sum[j][i]=sum[j][i-1];
        sum[pri[i]][i]++;
    }
}

void run()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    printf("Case #%d: %d\n",cas++,sum[k][b]-sum[k][a-1]);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    pre();
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
