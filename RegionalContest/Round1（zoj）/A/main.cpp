#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 500;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2

int a[N];

void run()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans = 0;
    for(int i=2;i<=n-1;i++) if(a[i]>a[i-1] && a[i]>a[i+1]) ans++;
    printf("%d\n",ans);
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
