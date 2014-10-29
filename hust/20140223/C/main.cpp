#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 40

using namespace std;

struct node{
    char name[N];
    int check,len;
    int next[N];
};

node r[N];
int ans,pr;

void buftoname(char *buf,char *name1,char *name2)
{
    int pbuf,pn;
    pbuf=pn=0;
    for(;buf[pbuf]!='-';)    name1[pn++]=buf[pbuf++];
    name1[pn]='\0';
    pbuf++;pn=0;
    for(;buf[pbuf]!='\0';)   name2[pn++]=buf[pbuf++];
    name2[pn]='\0';
}

int find(char *s)
{
    int i;
    for(i=0;i<pr;i++)
        if(strcmp(s,r[i].name)==0) return i;
    strcpy(r[pr].name,s);
    return pr++;
}

void dfs(int k)
{
    if(r[k].check==1) return;
    r[k].check=1;
    ans++;
    int i;
    for(i=0;i<r[k].len;i++)
        dfs(r[k].next[i]);
}

int main()
{
    freopen("in","r",stdin);
    memset(r,0,sizeof(r));
    ans=-1;pr=0;
    char buf[N],name1[N],name2[N];
    int p1,p2;
    gets(r[pr++].name);
    while(gets(buf)!=NULL)
    {
        if(strcmp(buf,"#")==0) break;
        buftoname(buf,name1,name2);
//        printf("%s %s\n",name1,name2);
        p1=find(name1);
        p2=find(name2);
//        printf("p1:%d p2:%d\n",p1,p2);
        r[p1].next[r[p1].len++]=p2;
        r[p2].next[r[p2].len++]=p1;
    }
    dfs(0);
    printf("%d\n",ans);
    return 0;
}
