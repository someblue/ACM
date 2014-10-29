#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 200005;

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

struct _node {
    int lcp,num[2];
    _node(int a=0,int b=0,int c=0)
    {
        lcp = a;
        num[0]=b;
        num[1]=c;
    }
    friend bool operator < (const _node &a, const _node &b)
    {
        return a.lcp < b.lcp;
    }
};

char s1[N],s2[N];
int k,n,len,top;
ll sum[2];
_node stk[N];
_sa sa;

inline int in(int x)
{
    return sa.sa[x]<len;
}
void update(int lcp,int i)
{
    int cnt[2];
    cnt[0]=cnt[1]=0;
    cnt[i]=1;
    while(top && lcp <= stk[top-1].lcp)
    {
        cnt[0]+=stk[top-1].num[0];
        cnt[1]+=stk[top-1].num[1];
        sum[0]-=stk[top-1].lcp * stk[top-1].num[0];
        sum[1]-=stk[top-1].lcp * stk[top-1].num[1];
        --top;
    }
    stk[top++]=_node(lcp,cnt[0],cnt[1]);
    sum[0]+=stk[top-1].lcp * stk[top-1].num[0];
    sum[1]+=stk[top-1].lcp * stk[top-1].num[1];
}
ll get(int i)
{
    return sum[i];
}

void run()
{
    top=0;sum[0]=sum[1]=0;
    scanf("%s%s",s1,s2);
    strcpy(sa.s,s1);
    strcat(sa.s,"$");
    strcat(sa.s,s2);
    sa.build_sa(256);
    n=strlen(sa.s);
    len=strlen(s1);
    ll ans=0;
    for(int i=2;i<n;++i)
    {
        if(sa.ht[i]<k)  {top=0;sum[0]=sum[1]=0;continue;}
        update(sa.ht[i]-k+1,in(i-1));
        ans+=get(!in(i));
    }
    printf("%I64d\n",ans);
}

int main()
{
    freopen("case.txt","r",stdin);
    while(scanf("%d",&k)!=EOF && k)
        run();
    return 0;
}
