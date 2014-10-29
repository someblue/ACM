#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
const int INF=1<<30;
const double eps=1e-6;
const int N = 200010;

struct _edge{
    int u,v,next;
    bool w;
};
_edge e[N];
int first[N],n;
vector<int> ans;

int dfs(int u,int dep)
{
    int res = (dep+1)/2;
    for(int i=first[u];i!=-1;i=e[i].next)
    {
        int v = e[i].v;
        int tmp = dfs(v,dep+1);
        if(e[i].w) tmp--;
        else if(tmp>dep)
        {
            ans.push_back(i);
            tmp--;
        }
        res = max(res,tmp);
    }
    return res;
}

void run()
{
    int u,v;
    char s[20];
    memset(first,-1,sizeof(first));
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&v,&u);
        e[i].u = u;
        e[i].v = v;
        scanf("%s",s);
        if(s[0]=='a')
            e[i].w=0,scanf("%s",s);
        else
            e[i].w=1;
        e[i].next = first[u];
        first[u] = i;
    }
//    for(int i=1;i<n;i++)
//        cout<<e[i].u << ' ' << e[i].v << ' ' << e[i].w<<endl;
    ans.clear();
    dfs(1,0);
    printf("%d\n",ans.size());
    if(!ans.empty()) printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    puts("");
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
