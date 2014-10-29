#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define REP(i,n) for(i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-9;
const int N = 550;
int cas = 1;

double fabs(double x)
{
    return x>=0?x:-x;
}

int n,X[N],Y[N];

struct Line
{
    int x;
    int y;
    double k;
    bool operator < (const Line &rhs) const
    {
        return x<rhs.x||(x==rhs.x&&y<rhs.y)||(x==rhs.x&&y==rhs.y&&k<rhs.k);
    }
    void push(int i,int j)
    {
        x=X[i]+X[j];
        y=Y[i]+Y[j];
        if(Y[i]==Y[j])
        {
            k=1e15;
            return;
        }
        k=(1.0*(X[i]-X[j]))/(1.0*(Y[i]-Y[j]));
    }
}data[N*N];

ll ans;

inline bool equ(double x)
{
    return fabs(x)<eps;
}
void solve(int lf,int rg)
{
//    printf("left=%d right=%d\n",lf,rg);
    ll cnt = 0;
//    ll t=ans;
    double k = data[lf].k;
    for(int i=lf+1;i<rg;i++)
    {
        if(!equ(data[i].k-k))
        {
            cnt = i-lf;
            k = data[i].k;
        }
//        if(lf==12)
//            cout<<cnt<<' '<<data[i].k<<' '<<k<<endl;
        ans += cnt;
    }
//    cout<<lf<<' '<<rg<<' '<<ans-t<<endl;
}

void run()
{
    if(n<4)
    {
        puts("0");
        return;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        scanf("%d%d",&X[i],&Y[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            data[cnt++].push(i,j);
    sort(data,data+cnt);
//    for(int i=0;i<cnt;i++)
//        printf("%d %d %lf\n",data[i].x,data[i].y,data[i].k);
    ans=0;
    int x,y,l,i;
    x=data[0].x;
    y=data[0].y;
    l=0;
    for(i=1;i<cnt;i++)
    {
        if(data[i].x!=x || data[i].y!=y)
        {
            solve(l,i);
            l=i;
            x=data[i].x;
            y=data[i].y;
        }
    }
    solve(l,cnt);
    printf("%I64d\n",ans);
}

int main()
{
    #ifdef LOCAL
    freopen("in","r",stdin);
    #endif
    while(scanf("%d",&n)&&n)
        run();
    return 0;
}
