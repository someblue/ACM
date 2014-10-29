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
const int N = 40005;

int n,m;
int a[N];
map<int,int> ms;

void add(int i,int v)
{
    if(ms.find(i)==ms.end())    ms[i]=v;
    else    ms[i]+=v;
}

int get(int i)
{
    if(ms.find(i)==ms.end())    return 0;
    else    return ms[i];
}

void run()
{
    ms.clear();
    int i,idx,sum;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]==m) {a[i]=0;idx=i;}
        else if(a[i]>m) a[i]=1;
        else    a[i]=-1;
    }
    add(0,1);
    for(sum=0,i=idx-1;i>0;--i)
    {
        sum += a[i];
        add(sum,1);
    }
//    for(map<int,int>::iterator it=ms.begin();
//        it!=ms.end();it++)
//        {
//            printf("%d: %d\n",it->first,it->second);
//        }
    int ans=get(0);
    for(sum=0,i=idx+1;i<=n;++i)
    {
        sum+=a[i];
        ans+=get(-sum);
    }
    printf("%d\n",ans);
}

int main()
{
//    freopen("case.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
        run();
    return 0;
}
