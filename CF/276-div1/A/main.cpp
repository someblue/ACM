#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 100;
int cas = 1;

bool a[N],b[N],c[N];
int mx;

void ltob(ll x,bool *arr)
{
    int sz=0;
    while(x)
        arr[sz++]=x&1,x>>=1;
    if(mx<sz) mx=sz;
}

bool judge(int p)
{
    for(;p>=0;p--)
        if(a[p]==0) return 0;
    return 1;
}

void work(int p)
{
    if(p<0) return;
    if(judge(p))
        for(int i=p;i>=0;i--)   c[i]=1;
    else{
        if(a[p] == b[p]) c[p]=a[p],work(p-1);
        else{
            for(int i=p-1;i>=0;i--)
                c[i]=1;
        }
    }
}

void run()
{
    ll l,r;
    scanf("%I64d%I64d",&l,&r);
    if(l==r) cout<<l<<endl;
    else{
        mx=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ltob(r,a);
        ltob(l,b);

//        cout<<"a:";for(int i=mx-1;i>=0;i--) printf("%d",a[i]); puts("");
//        cout<<"b:";for(int i=mx-1;i>=0;i--) printf("%d",b[i]); puts("");
        memset(c,0,sizeof(c));
        work(mx-1);
//        cout<<"c:";for(int i=mx-1;i>=0;i--) printf("%d",c[i]); puts("");
        ll ans = 0, base = 1;
        for(int i=0;i<mx;i++){
            if(c[i]) ans+=base;
            base<<=1;
        }
        cout<<ans<<endl;
    }
}

int main()
{
    #ifdef LOCAL
//    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
