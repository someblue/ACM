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

const int x = 12321;
int n,m;
ull hl[N],hr[N];
char s[N];
set<string> myset;

char ans[][10] = {"NO", "YES"};

void run()
{
    myset.clear();
    for(int j=0; j<n; j++)
    {
        scanf("%s",s);
        int sz = strlen(s);
        for(int i=0; i<sz; i++)
        {
            char c = s[i];
            for(int k=0; k<3; k++)
            {
                if(k+'a'==c) continue;
                s[i] = k+'a';
                myset.insert(string(s));
            }
            s[i] = c;
        }
    }
    for(int j=0; j<m; j++)
    {
        scanf("%s",s);
        if(myset.count(string(s)))
            puts("YES");
        else
            puts("NO");
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
