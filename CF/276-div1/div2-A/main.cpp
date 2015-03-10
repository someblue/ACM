#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100010;
int cas = 1;

bool vis[N];
int a,m;

void run()
{
    memset(vis,0,sizeof(vis));
    if(a%m==0){
        puts("Yes");
        return;
    }
    while(true)
    {
        a = (a+a%m)%m;
        if(a==0){
            puts("Yes");
            return;
        }
        if(vis[a]){
            puts("No");
            return;
        }
        vis[a]=1;
    }
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    while(cin>>a>>m)
        run();
    return 0;
}
