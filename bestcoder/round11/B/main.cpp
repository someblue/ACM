#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2

int a[N],n,ans[N];
bool vis[N];

void run()
{
    for(int i=0;i<n;i++ ) scanf("%d",a+i);
    sort(a,a+n);
    memset(vis,0,sizeof(vis));
    int i;
    for(i=0;i<n;i++)
        if(a[i]&1)
            break;
    if(i>=n)
    {
        puts("-1");
        return;
    }
    ans[n-1]=a[i];
    vis[i]=1;
    int p=0;
    for(i=n-1;i>=0;i--)
    {
        if(vis[i]) continue;
        ans[p++]=a[i];
    }
    if(ans[0]==0)
        printf("-1");
    else
        for(i=0;i<n;i++)
            printf("%d",ans[i]);
    puts("");
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
