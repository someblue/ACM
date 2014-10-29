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
const int N = 5842;
typedef long long ll;
ll ans[N+100],cnt;

void pre()
{
    cnt=1;
    priority_queue<ll,vector<ll>,greater<ll> > que;
    que.push(1);
    ll lst=-1;
    while(!que.empty() && cnt<=N)
    {
        ll u = que.top();
        que.pop();
        if(u == lst) continue;
        lst = u;
        ans[cnt++]=u;
        que.push(u*2);
        que.push(u*3);
        que.push(u*5);
        que.push(u*7);
    }
}
char s[][5]={"th","st","nd","rd","th","th","th","th","th","th"};
int main()
{
    freopen("case.txt","r",stdin);
    pre();
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int k;
        k=n%10;
        if(n/10%10==1) k=9;
        printf("The %d%s humble number is %I64d.\n",n,s[k],ans[n]);
    }
    return 0;
}
