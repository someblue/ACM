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

unsigned short sum[11][11][N];// 位 数字 下标
int n,m;
int a[N];

inline int lowbit(int x)
{
    return x&-x;
}

inline void add(int i,int j,int x,int d)
{
    while(x<=n)
    {
        sum[i][j][x]+=d;
        x+=lowbit(x);
    }
}

inline int get(int i,int j,int x)
{
    if(x==0) return 0;
    int ret = 0;
    while(x>0)
    {
        ret += sum[i][j][x];
        x -= lowbit(x);
    }
    return ret;
}


void run()
{
    memset(sum,0,sizeof(sum));
    int i,j,x,d;
    int l,r,p;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i]=x;
        d=1;
        while(x)
        {
            add(d,x%10,i,1);
//            add(d,x%10,i+1,-1);
            d++;
            x/=10;
        }
        for(;d<=10;d++)
            add(d,0,i,1);
    }
    char s[5];
    while(m--)
    {
        scanf("%s",s);
        if(s[0]=='Q')
        {
            scanf("%d%d%d%d",&l,&r,&d,&p);
            printf("%d\n",get(d,p,r)-get(d,p,l-1));
        }
        else
        {
            scanf("%d",&i);
            x=a[i];
            d=1;
            while(x)
            {
                add(d,x%10,i,-1);
                d++;
                x/=10;
            }
            for(;d<=10;d++)
                add(d,0,i,-1);
            scanf("%d",&x);
            a[i]=x;
            d=1;
            while(x)
            {
                add(d,x%10,i,1);
                d++;
                x/=10;
            }
            for(;d<=10;d++)
                add(d,0,i,1);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
