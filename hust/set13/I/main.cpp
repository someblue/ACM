#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 140000;

int n,p,q;
bool sg[N];

void run()
{
    if(n<=p)
    {
        puts("LOST");
        return;
    }
    memset(sg,0,n+1);
//    memset(sg,0,q+1);
    for(int i=0;i<=p;++i)   sg[i]=0;
    for(int i=p+1;i<=q;++i) sg[i]=1;
//    int len=q-p+1;
    for(int i=1;i+p<=n;++i)
    {
        if(sg[i])   continue;
        for(int j=i+p;j<=i+q;++j)
            sg[j]=1;
    }
    if(sg[n])   puts("WIN");
    else        puts("LOST");
    for(int i=0;i<=n;++i)
    {
        if(i%10==0) cout<<endl;
           cout<<sg[i]<<' ';
    }
    cout<<endl;
}

void run2()
{
    if(n==0)
    {
        puts("LOST");
        return;
    }
    n %= (p+q);
    if(1<=n && n<=p)    puts("LOST");
    else    puts("WIN");
}

int main()
{
    while(scanf("%d%d%d",&n,&p,&q)!=EOF)
        run2();
    return 0;
}
