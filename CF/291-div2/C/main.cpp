#include <bits/stdc++.h>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 600010;
int cas = 1;

struct _node {
    int len, lack, l, r;
    friend bool operator < (const _node a, const _node b)
    {
        return a.l < b.l || (a.l==b.l && a.r<b.r) || (a.l==b.l && a.r==b.r && a.len<b.len) || (a.l==b.l && a.r==b.r && a.len==b.len && a.lack<b.lack);
    }
};

const ull x = 10000001234567LL;
int n,m;
ull hl[N],hr[N];
char s[N], s2[N];
map<_node, int> myset;

char ans[][10] = {"NO", "YES"};

int special()
{
    scanf("%s%s",s,s2);
    int t = 0;
    if(strlen(s)!=strlen(s2)) return 0;
    for(int i=0; s[i]; i++)
        if(s[i]!=s2[i])
            t++;
    return t==1;
}

void run()
{
    if(n==1 && m==1)
    {
        cout << ans[special()] << endl;
        return;
    }
    myset.clear();
    _node node;
    for(int j=0; j<n; j++)
    {
        scanf("%s",s+1);
        int sz = strlen(s+1);
        hl[0] = 0;
        for(int i=1; i<=sz; i++) hl[i] = hl[i-1]*x + s[i];
        hr[sz+1] = 0;
        for(int i=sz; i>=1; i--) hr[i] = hr[i+1]*x + s[i];
        node.len = sz;
        for(int i=1; i<=sz; i++)
        {
            node.lack = i;
            node.l = hl[i-1];
            node.r = hr[i+1];
            int t = s[i]-'a';
            myset[node] |= 7^(1<<t);
        }
    }
    for(int j=0; j<m; j++)
    {
        scanf("%s",s+1);
        int sz = strlen(s+1);
        hl[0] = 0;
        for(int i=1; i<=sz; i++) hl[i] = hl[i-1]*x + s[i];
        hr[sz+1] = 0;
        for(int i=sz; i>=1; i--) hr[i] = hr[i+1]*x + s[i];
        node.len = sz;
        bool flag = 0;
        for(int i=1; i<=sz; i++)
        {
            node.lack = i;
            node.l = hl[i-1];
            node.r = hr[i+1];
            if(myset.count(node))
            {
                int t = s[i]-'a';
                int t2 = myset[node];
                if(t2 & (1<<t)){
                    flag = 1;
                    break;
                }
            }
        }
        puts(ans[flag]);
    }
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
