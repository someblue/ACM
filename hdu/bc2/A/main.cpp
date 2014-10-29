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
const int N = 10005;

struct _node {
    int t,w;
    friend bool operator < (const _node a,const _node b)
    {
        return a.t<b.t || (a.t==b.t && a.w<b.w);
    }
};

_node mes[N*2];
char s[20];

int get()
{
    scanf("%s",s);
    int h,m;
    h = (s[0]-'0')*10 + s[1]-'0';
    m = (s[3]-'0')*10 + s[4]-'0';
    return h*60+m;
}

void run()
{
    int n,x;
    int t1,t2;
    int i;
    scanf("%d",&n);
    n*=2;
    for(i=0;i<n;i+=2)
    {
        scanf("%d",&x);
        t1 = get();
        t2 = get();
        mes[i].t = t1;
        mes[i+1].t = t2;
        mes[i].w = x;
        mes[i+1].w = -x;
    }
    sort(mes,mes+n);
    int ans = 0;
    int sum = 0;
    for(i=0;i<n;++i)
    {
        sum+=mes[i].w;
        if(ans < sum)   ans = sum;
    }
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
