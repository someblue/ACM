#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 45;
bool prm[N],vis[N];
int ans[N];
int n;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

void build()
{
    memset(prm,1,sizeof(prm));
    for(int i=2;i<N;++i)
        if(prm[i])
        for(int j=i*2;j<N;j+=i)
            prm[j]=0;
}

void print()
{
    printf("%d",ans[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",ans[i]);
    puts("");
}

void dfs(int cur)
{
    if(cur==n)
    {
        if(prm[ans[cur]+1])
            print();
    }
    else
    {
        int k = ans[cur];
        for(int i=2;i<=n;++i)
        {
            if(!vis[i] && prm[k+i])
            {
                ans[cur+1]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    build();
    int cas=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        ans[1]=1;
        printf("Case %d:\n",cas++);
        dfs(1);
        puts("");
    }
    return 0;
}
