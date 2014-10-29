#include <iostream>
#include <cstdio>
#include <cstring>
#define N 50005
using namespace std;

int n,m;

struct _bit{
    int sum[N];
    void init()
    {
        memset(sum,0,sizeof(sum));
    }
    int lowbit(int x)
    {
        return x& -x;
    }
    void add(int x)
    {
        while(x<=n){
            ++sum[x];
            x+=lowbit(x);
        }
    }
    int get(int x)
    {
        int res=0;
        while(x>0){
            res+=sum[x];
            x-=lowbit(x);
        }
        return res;
    }
};
_bit bl,br;

void run()
{
    int cmd,l,r;
    int cnt=0;
    bl.init();
    br.init();
    while(m--)
    {
        scanf("%d%d%d",&cmd,&l,&r);
        if(cmd==1)
        {
            ++cnt;
            bl.add(l);
            br.add(r);
        }
        else
        {
            printf("%d\n",cnt-br.get(l-1)-(bl.get(n)-bl.get(r)));
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
