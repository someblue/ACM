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
const int N = 1000005;

struct _sa{
    char s[N];
    int sa[N],t[N],t2[N],c[N],n;
    int rk[N],ht[N];
    void build_sa(int m)
    {
        int i,j,k,*x=t,*y=t2;
        n = strlen(s);
        for(i=0;i<m;++i) c[i]=0;
        for(i=0;i<n;++i) c[x[i]=s[i]]++;
        for(i=1;i<m;++i) c[i]+=c[i-1];
        for(i=n-1;i>=0;--i) sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1)
        {
            int p=0;
            for(i=n-k;i<n;++i) y[p++]=i;
            for(i=0;i<n;++i) if(sa[i]>=k) y[p++] = sa[i]-k;

            for(i=0;i<m;++i) c[i]=0;
            for(i=0;i<n;++i) c[x[y[i]]]++;
            for(i=0;i<m;++i) c[i] += c[i-1];
            for(i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];

            swap(x,y);
            p=1;x[sa[0]]=0;
            for(i=1;i<n;++i)
                x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
            if(p>=n) break;
            m = p;
        }

        k=0;
        for(i=0;i<n;++i) rk[sa[i]]=i;
        for(i=0;i<n;++i)
        {
            if(k) k--;
            j=sa[rk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            ht[rk[i]]=k;
        }
    }
};

_sa sa;

void run()
{
    scanf("%s",sa.s);
    sa.build_sa(256);
    int minn=INF;
}

int main()
{
//    freopen("case.txt","r",stdin);
    int _;
    scanf("%d",&_);
    while(_--)
        run();
    return 0;
}
