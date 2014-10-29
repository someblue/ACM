#include <iostream>
#include <cstdio>
#include <cstring>
#define N 30
#define MN 110

using namespace std;

struct node{
    int len;
    int next[N];
    bool c,r;
    node(){len=0;c=r=0;}
};

node ju[N];

void clearcheck()
{
    int i;
    for(i=0;i<N;i++)
        ju[i].c=0;
}

void un(int a,int b)
{
    ju[a].next[ju[a].len++]=b;
}

void tar(int n)
{
    ju[n].r=1;
    if(ju[n].c||(ju[n].len==0)) return;
    ju[n].c=1;
    int i;
    for(i=0;i<ju[n].len;i++)
    {
        tar(ju[n].next[i]);
    }
}

bool fi(int a,int b)
{
    if(a==b) return 1;
    if(ju[a].c||(ju[a].len==0)) return 0;
    ju[a].c=1;
    int i;
    for(i=0;i<ju[a].len;i++)
        if(fi(ju[a].next[i],b))
            return 1;
    return 0;
}

inline void in(char *p)
{
    while(scanf("%c",p))
        if((*p)>='A'&&(*p)<='Z')
            return;
}

void print()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<ju[i].len;j++)
            printf("%d ",ju[i].next[j]);
        printf("\n");
    }
}

int main()
{
    int n,m,i;
    char aa,bb;
    int a,b,t[MN],tcnt=0,cm;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cm);
        if(cm==1)
        {
            in(&aa);
            t[tcnt++]=aa-'A';
        }
        else
        {
            in(&aa);in(&bb);
            a=aa-'A';b=bb-'A';
            un(a,b);
            if(cm==3) un(b,a);
        }
    }
    for(i=0;i<tcnt;i++)
    {
        clearcheck();
        tar(t[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&cm);
        if(cm==1)
        {
            in(&aa);
            a=aa-'A';
            if(ju[a].r) printf("yes\n");
            else printf("no\n");
        }
        else
        {
            in(&aa);in(&bb);
            a=aa-'A';b=bb-'A';
            clearcheck();
            if(cm==2)
                if(fi(a,b)) printf("yes\n");
                else printf("no\n");
            else
                if(fi(a,b)&&(clearcheck(),fi(b,a))) printf("yes\n");
                else printf("no\n");
        }
    }
//    print();
    return 0;
}
