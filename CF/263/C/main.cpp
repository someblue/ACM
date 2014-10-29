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
typedef long long ll;
const int INF=1<<30;
const double eps=1e-6;
const int N = 100010;

ll sum[2*N];
int n,s,q;
inline int lowbit(int x)
{
    return x&-x;
}

inline void add(int x,int v)
{
    while(x<=n)
    {
        sum[x]+=v;
        x+=lowbit(x);
    }
}
inline ll get(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=sum[x];
        x-=lowbit(x);
    }
    return res;
}

void run()
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        add(i,1);
//    for(int i=1;i<=n;i++)
//        cout<<get(i)-get(i-1)<<' '; cout<<endl;
    s=0;
    int op,l,r,p;
    while(q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&p);
            for(int i=1;i<=p;i++)
            {
//                cout<<s+2*p-i+1<<','<<sum[s+i]<<"   ";
                add(s+2*p-i+1,get(s+i)-get(s+i-1));
            }
//            cout<<endl;
            s+=p;
//            for(int i=1;i<=n;i++)
//                cout<<get(i)-get(i-1)<<' '; cout<<endl;
        }
        else
        {
            scanf("%d%d",&l,&r);
            printf("%I64d\n",get(s+r)-get(s+l));
        }
    }
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&q)!=EOF)
        run();
    return 0;
}
