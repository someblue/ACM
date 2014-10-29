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
const int N = 1005;
bool fir;

struct _node
{
    int t,id,num;
};

char s[20];
int get()
{
    scanf("%s",s);
    int h,m;
    h = (s[0]-'0')*10 + s[1]-'0';
    m = (s[3]-'0')*10 + s[4]-'0';
    return h*60+m;
}

int kinds,times,k,m;
_node mes[N];
int now,qf,df;

inline void print(int x)
{
    int h = x/60 %24;
    int m = x%60;
    printf("%02d:%02d\n",h,m);
}

void run()
{
    if(fir) fir=0;
    else printf("\n");
    int i;
    scanf("%d%d%d%d",&kinds,&times,&k,&m);
    for(i=1;i<=m;++i)
    {
        mes[i].t = get();
        scanf("%d%d",&mes[i].id,&mes[i].num);
    }
    qf = 1;
    int id,num,now;
    id = -1;
    now = -1;
    while(qf<=m)
    {
        if(now < mes[qf].t)
        {
            now = mes[qf].t+times;
            id = mes[qf].id;
            num = mes[qf].num;
        }

        if(id != mes[qf].id)
        {
            now += times;
            id = mes[qf].id;
            num = k;
        }

        if(num >= mes[qf].num)
        {
            print(now);
            num -= mes[qf].num;
            qf++;
        }
        else
        {
            now += times;
            num += k;
            mes[qf].num -= num;
        }
    }
}



int main()
{
//    freopen("case.txt","r",stdin);
    fir=1;
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
