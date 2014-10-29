#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1010

using namespace std;

struct node{
    int num,c,last[N],len[N],ans;
    bool check;
};

node ss[N];
int pc[N];

int div(int p)
{
    if(ss[p].num==0) return ss[p].c;
    if(ss[p].check) return ss[p].ans;
    int i,ans,t;
    for(ans=0,i=0;i<ss[p].num;i++)
    {
        t=div(ss[p].last[i])-ss[p].len[i];
        ans+=(t>20?t:20);
    }
    ss[p].check=1;
    return ss[p].ans=ans/ss[p].num;
}

int main()
{
    int n,m,k,pos,u,v,w,ans;
    int i;
    while(scanf("%d%d%d%d",&n,&m,&k,&pos)!=EOF)
    {
        memset(ss,0,sizeof(ss));
        for(i=0;i<k;i++)
            scanf("%d",&pc[i]);
        for(i=0;i<k;i++)
            scanf("%d",&ss[pc[i]].c);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            ss[v].last[ss[v].num]=u;
            ss[v].len[ss[v].num]=w;
            ss[v].num++;
        }
        ans=div(pos);
        if(ans>=46) printf("%d\n",ans);
        else printf("I bought a watch last year!\n");
    }
    return 0;
}
