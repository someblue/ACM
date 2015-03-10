#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 3010;
int cas = 1;

int a[N],b[N],n;
vector<pii> ans;

inline void sw(int &x,int &y)
{
    int tmp = x;
    x=y;
    y=tmp;
}

void run()
{
    ans.clear();
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) b[i]=a[i];
    sort(b,b+n);
    int p;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        for(p=i+1;p<n;p++)
            if(a[p]!=b[p] && a[p]==b[i]) break;
        sw(a[i],a[p]);
        ans.push_back(make_pair(i,p));
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
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
