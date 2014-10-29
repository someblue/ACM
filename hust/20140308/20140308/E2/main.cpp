#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define END -1

using namespace std;

struct node{
    int w,next;
    friend bool operator < (node a,node b)
    {
        return a.w>b.w;
    }
};

node num[N];
int n,first,k;

void buildnext()
{
    int i;
    first = 0;
    for(i=0;i<n-1;i++)
        num[i].next = i+1;
    num[n-1].next = END;
}

void movemax()
{
    if(num[first].w >= num[num[first].next].w) return;
    int first_copy=first,p,q;
    first = num[first].next;
    p=first_copy;
    q=num[p].next;
    while(q!=END)
    {
        if(num[first_copy].w >= num[q].w)
        {
            num[p].next = first_copy;
            num[first_copy].next = q;
            break;
        }
        p = q;
        q = num[q].next;
    }
    if(q==END)
    {
        num[p].next = first_copy;
        num[first_copy].next = END;
    }
}

void print()
{
    int next;
//    for(i=0;i<n;i++)
//        printf("%d %d\n",num[i].w,num[i].next);
    next = first;
    while(next!=END)
    {
        printf("%d ",num[next].w);
        next = num[next].next;
    }
    cout<<endl;
}

void text()
{
    while(scanf("%d",&num[first].w)!=EOF)
    {
        movemax();
        print();
    }
}

void run()
{
    int now,kk=k-1;
    for(now=1;;now++)
    {
        num[first].w -= kk;
        movemax();
        //printf("now:%d ",now);print();
        if(num[first].w<=now) break;
    }
    printf("%d\n",now);
}

int main()
{
    freopen("in","r",stdin);
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i].w);
    scanf("%d",&k);
    sort(num,num+n);
    buildnext();
    //print();
    //text();
    run();
    return 0;
}
