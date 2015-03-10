#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 310;
int cas = 1;

int n;
int p[N];
char g[N][N];

void run()
{
    memset(g,0,sizeof(g));
    for(int i=1; i<=n; i++) scanf("%d",p+i);
    for(int i=1; i<=n; i++)
        scanf("%s",g[i]+1);
    for(int k=1; k<=n; k++)
    {
        bool flag = 1;
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
        {
            if(g[i][j]=='1' && p[i]>p[j])
            {
                int tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
                flag = 0;
            }
        }
        if(flag) break;
    }
    printf("%d",p[1]);
    for(int i=2; i<=n; i++) printf(" %d",p[i]);
    cout<<endl;
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
