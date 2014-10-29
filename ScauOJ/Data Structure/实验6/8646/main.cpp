#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1000
#define NN 10
using namespace std;
struct _
{
    char key[5];
    int next;
} r[N];
int f[NN],e[NN];

void show()
{
    int p=r[0].next;
    for(;p;p=r[p].next) cout<<r[p].key<<' ';
    cout<<endl;
}

void dis(int i)
{
    int j;
    for(j=0;j<NN;j++)f[j]=0;
    for(int p=r[0].next;p;p=r[p].next)
    {
        j=r[p].key[i]-'0';
        if(!f[j]) f[j]=p;
        else r[e[j]].next=p;
        e[j]=p;
    }
}

void col(int i)
{
    int j,t;
    for(j=0;!f[j];j++);
    r[0].next = f[j]; t = e[j];
    while(j<NN)
    {
        for(j++;j<NN-1 && !f[j]; j++);
        if(f[j]) {r[t].next = f[j]; t=e[j];}
    }
    r[t].next = 0;
}

int main()
{
    int n,i;
    cin>>n;
    r[0].next = 1;
    for(i=1; i<=n; i++)
    {
        cin>>r[i].key[0]>>r[i].key[1]>>r[i].key[2];
        r[i].key[3]='\0';
        r[i].next=i+1;
    }
    r[n].next = 0;
    for(i=0;i<3;i++)
    {
        dis(2-i);
        col(2-i);
        show();
    }
    return 0;
}
