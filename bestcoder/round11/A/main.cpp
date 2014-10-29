#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;

//  http://acm.zju.edu.cn/mdj2014/contestInfo.do?contestId=2


int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    int n,m,x,y;
    while(cin>>n>>m>>x>>y)
    {
        if(n-x == x && m-y==y)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
