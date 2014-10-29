#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 20

using namespace std;

int fa[N];

void init()
{
    int i;
    for(i=0;i<N;i++)
        fa[i]=i;
}

int find(int a)
{
    if(fa[a]!=a) fa[a]=find(fa[a]);
    return fa[a];
}

void run()
{
    int n,m,i,a,b,ans;
    while(cin>>n>>m,n)
    {
        init();ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            a=find(a);b=find(b);
            fa[a]=b;
        }
        for(i=0;i<n;i++)
            if(find(i)==i) ans++;
        cout<<ans<<endl;
//        for(i=0;i<n;i++)
//            printf("%3d",i);
//        cout<<endl;
//        for(i=0;i<n;i++)
//            printf("%3d",fa[i]);
//        cout<<endl;
    }
}

int main()
{
    //freopen("case.txt","r",stdin);
    run();
    return 0;
}

/*
WA
*/

