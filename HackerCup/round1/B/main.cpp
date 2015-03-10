#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1000010;
int cas = 1;

int root=0, cnt;

struct _node {
    int nx[26];
    void init()
    {
        memset(nx,-1,sizeof(nx));
    }

}node[N];

void reset()
{
    cnt=1;
}
void insert(int r, char *s, int p, int &len, int &ans)
{
//    if(p==len)
//    {
//        if(ans==-1) ans=len;
//        return;
//    }
//    if(node[r].nx[s[p]-'a']==-1)
//    {
//        if(ans==-1)
//            ans = p+1;
//        node[cnt].init();
//        node[r].nx[s[p]-'a'] = cnt++;
//    }
//    insert(node[r].nx[s[p]-'a'], s, p+1, len, ans);

    while(p<len)
    {
        if(node[r].nx[s[p]-'a']==-1)
        {
            if(ans==-1)
                ans = p+1;
            node[cnt].init();
            node[r].nx[s[p]-'a'] = cnt++;
        }
        r=node[r].nx[s[p]-'a'];
        p++;
    }
    if(ans==-1) ans=len;
}
char s[N];
void run()
{
    node[root].init();
    cnt=1;
    int n;
    scanf("%d",&n);
//    cout << n << endl;
    int sum=0,ans;
    while(n--)
    {
        scanf("%s",s);
        ans=-1;
        int l=strlen(s);
//        if(cas==5) cout << l << endl;
        insert(root,s,0,l,ans);
//        cout << cnt << endl;
//        printf("ans: %d\n",ans);
        sum += ans;
    }
    printf("Case #%d: %d\n",cas++,sum);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
