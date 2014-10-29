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
#define N 1010
#define REP(i,n) for(i=0;(i)<(n);(i)++)
using namespace std;
const int INF=1<<30;
const double eps=1e-6;

struct _node{
    int a,b,c;
    friend bool operator < (_node a, _node b)
    {
        return a.c>b.c;
    }
}mes[N];

void run()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int v,n,i;
        cin>>v>>n;
        REP(i,n)    cin>>mes[i].a>>mes[i].b, mes[i].c=mes[i].b-mes[i].a;
        sort(mes,mes+n);
        bool ok=1;
        int vv=0;
        REP(i,n)
        {
            if(vv+mes[i].b>v)   {ok=0;break;}
            vv+=mes[i].a;
        }
        cout<<(ok?"Yes":"No")<<endl;
    }
}

int main()
{
//    freopen("case.txt","r",stdin);
    run();
    return 0;
}
