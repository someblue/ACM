#include <iostream>
#include <cstdio>
#include <cstring>
#define left(x) (1<<(x))
using namespace std;
const int N = 105;

int n;
int a[N];
int cnt[32];

void run()
{
    memset(cnt,0,sizeof(cnt));
    int xors=0,x,i,idx;
    while(n--)
    {
        scanf("%d",&x);
        xors ^= x;
        for(i=0;left(i)<=x;++i)
        {
            if(x & left(i))
                ++cnt[i];
        }
    }
    idx = -1;
    for(i=0;left(i)<=xors;++i)
        if(xors & left(i))
            idx = i;
    if(idx==-1) puts("0");
    else    printf("%d\n",cnt[idx]);
}

int main()
{
    while(scanf("%d",&n)!=EOF && n)
        run();
    return 0;
}
