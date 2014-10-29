#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;

struct _node
{
    int f,s,d,h;
} mes[N];

int n;

struct BIT{
    int sum[N],cnt[N];
    void reset()
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
    }
    inline int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x)
    {
        int k=x;
        while(x<=n){
            sum[x]+=k;
            cnt[x]++;
            x+=lowbit(x);
        }
    }
    void get(int &s, int &c,int x)
    {
        s=c=0;
        while(x>0){
            s+=sum[x];
            c+=cnt[x];
            x-=lowbit(x);
        }
    }
}bit;

inline bool cmp1(const _node a,const _node b)
{

}

void run()
{
    int i,j;
    bit.reset();
    for(i=1; i<=n; i++)   scanf("%d%d",&mes[i].f,&mes[i].s);
    mes[0].f=mes[0].s=-1;
    //getd

    //geth

    //count
}

int main()
{
    while(scanf("%d",&n)!=EOF)
        run();
    return 0;
}
