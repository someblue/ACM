#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define PB push_back
#define MS(x) memset(x,0,sizeof(x))
#define SZ size
#define rep(i,l,r) for(i=(l);i<(r);i++)
#define drep(i,l,r) for(int i=(l); i<(r); i++)
#define per(i,l,r) for(i=(r)-1;i>=l;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1010;
int cas = 1;

int n;
char name[N][15], pw[N][15];

inline bool modify(char *pw)
{
    int cnt = 0;
    for(int i=0; pw[i]; i++)
    {
        char &c = pw[i];
        if(c=='1') {
            c = '@';
        } else if(c=='0') {
            c = '%';
        } else if(c=='l') {
            c = 'L';
        } else if(c=='O') {
            c = 'o';
        } else continue;
        cnt++;
    }
    return cnt>0;
}

void run()
{
    vi ans;
    drep(i, 0, n)
    {
        scanf("%s%s", name[i], pw[i]);
        if(modify(pw[i]))
        {
            ans.push_back(i);
        }
    }
    if(ans.size()==0) {
        puts("No account is modified.");
    } else {
        printf("%d\n", ans.size());
        drep(i, 0, ans.size()) {
            printf("%s %s\n", name[ans[i]], pw[ans[i]]);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(~scanf("%d",&n) && n)
        run();
    return 0;
}
