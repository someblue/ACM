#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 300000;
const int M = 1000010;
int cas = 1;

int a[N];
bool vis[M];
int num[M];
int n,mxnum,ans;

void run()
{
    int x;
    mxnum=0;
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(mxnum<x) mxnum=x;
        vis[x]=1;
    }
    for(int i=1;i<=mxnum;i++)
    {
        if(vis[i]) num[i]=i;
        else num[i]=num[i-1];
    }
    ans=0;
    for(int aj=1;aj<=mxnum;aj++)
    {
        if(!vis[aj]) continue;
        if(ans<mxnum%aj) ans=mxnum%aj;
        for(int p=aj*2;p<=mxnum;p+=aj)
        {
            if(ans < num[p-1]%aj)
                ans = num[p-1]%aj;
        }
    }
    printf("%d\n",ans);
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
