#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010

using namespace std;

struct linklist
{
    int d;
    linklist *next;
};

int num[N];

void creat(int n,linklist &l)
{
    linklist *p,*q;
    l=(linklist *)malloc(sizeof(linklist));
    q=(linklist *)malloc(sizeof(linklist));
    l->next = q;
    q->d=num[0];
    int i;
    for(i=1; i<n; i++)
    {
        p = (linklist *)malloc(sizeof(linklist));
        p->d = num[i];
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

void movemax(int n,linklist &l)
{
    if(l->d > l->next->data) return;
    int i;
    linklist *p,*q;
    p = l->next;
    q = p;
    for(i=0; i<n-1; i++)
    {
        if(p->d > q->next->d)
        {
            l = p->next;
            p->next = q->next;
            q->next = p;
        }
    }
    if(i==n-1)
    {
        l=p->next;
        q->next = p;
        p->next = NULL;
    }
}

void print(int n,linklist &l)
{
    int i;
    linklist *p;
    p=l->next;
    for(i=0; i<n; i++)
    {
        printf("%d ",p->d);
        p = p->next;
    }
    printf("\n");
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,k;
    int i,j;
    linklist *l;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n,cmp);
    creat(n,l);
    print(n,l);
    return 0;
}
