#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
int cas = 1;

vector<int> v[4];
int n;

void run()
{
    int x;
    for(int i=1;i<=3;i++) v[i].clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        v[x].push_back(i);
    }
    n = min(v[1].size(),min(v[2].size(),v[3].size()));
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        printf("%d %d %d\n",v[1][i],v[2][i],v[3][i]);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
