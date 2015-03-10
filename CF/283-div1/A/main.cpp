#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

char s[N][N];
int n,m;
int a[N],b[N];

bool judge(int j)
{
    for(int i=2; i<=n; i++)
    {
        if(a[i-1]>=a[i])
        {
            if(s[i-1][j] < s[i][j]) a[i]=i;
            else if(s[i-1][j] == s[i][j]) a[i]=a[i-1];
            else return 0;
        }
    }
    return 1;
}

void run()
{
    for(int i=1; i<=n; i++)
        scanf("%s",s[i]+1);
    int ans=0;
    for(int i=1; i<=n; i++)
        b[i]=1;
//        for(int k=1; k<=n; k++)
//            printf("%d ",b[k]);
//        cout << endl;
    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++) a[i]=b[i];
        if(judge(j))
            for(int k=1; k<=n; k++) b[k]=a[k];
        else
        {
//            cout << "ans+: " << j << endl;
            ans++;
        }
//        printf("%d: ",j);
//        for(int k=1; k<=n; k++)
//            printf("%d ",b[k]);
//        cout << endl;
    }
    printf("%d\n",ans);
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
