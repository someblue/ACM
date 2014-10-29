#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define SN 12
typedef long long ll;
using namespace std;
struct node{
    char s1[SN],s2[SN];
    bool ok,check;
    friend bool operator < (node a,node b)
    {
        return strcmp(a.s1,b.s1)>0;
    }
};
node d[N];
int n;
void find(int &l,int &r,char s[])
{
    int i;
    l=r=-1;
    for(i=0;i<n;i++)
        if(strcmp(s,d[i].s1)==0){l=i;break;}
    for(;i<n;i++)
        if(strcmp(s,d[i].s1)!=0){r=i;break;}
}
bool dfs(char name[])
{
    int l,r;
    l=r=0;
    find(l,r,name);
    if(l==-1) return 1;
    if(d[l].ok==1) return 1;
    if(d[l].check==1) return 0;
    d[l].check=1;
    int i;
    for(i=l;i<r;i++)
        if(dfs(d[i].s2)==0) return 0;
    d[l].ok=1;
    d[l].check=0;
    return 1;
}
void run()
{
    int t,cas=1;
    int i;
    bool res;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,0,sizeof(d));
        res=1;
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
            scanf("%s%s",d[i].s1,d[i].s2);
        sort(d,d+n);
        for(i=0;i<n;i++)
        {
            if(dfs(d[i].s1)==0) {res=0;break;}
        }
        printf("Case %d: %s\n",cas++,res?"Yes":"No");
    }
}
int main()
{
    run();
    return 0;
}
