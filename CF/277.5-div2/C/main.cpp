#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 110;
int cas = 1;

int m,summ;
int s[N];

bool mindfs(int p,int sum)
{
    if(sum>p*9 || sum<0) return 0;
    if(p==1)
    {
        s[p]=sum;
        return 1;
    }
    int i=0;
    if(p==m) i=1;
    for(;i<=9;i++)
        if(i<=sum && mindfs(p-1,sum-i))
        {
            s[p]=i;
            return 1;
        }
    return 0;
}

bool maxdfs(int p,int sum)
{
    if(sum>(m-p+1)*9 || sum<0) return 0;
    if(p==m)
    {
        s[p]=sum;
        return 1;
    }
    for(int i=0;i<=9;i++)
        if(i<=sum && maxdfs(p+1,sum-i))
        {
            s[p]=i;
            return 1;
        }
    return 0;
}

void print()
{
    for(int i=m;i>0;i--)
        printf("%d",s[i]);
}

void run()
{
    if(summ==0)
    {
        if(m==1) puts("0 0");
        else puts("-1 -1");
        return;
    }
    if(mindfs(m,summ))
        print();
    else printf("-1");
    cout<<" ";
    if(maxdfs(1,summ))
        print();
    else printf("-1");
    cout<<endl;
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d",&m,&summ)!=EOF)
        run();
    return 0;
}
