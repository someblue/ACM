#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100
using namespace std;
int rec[N];
int a,b,n,cyc;
int f(int x)
{
    if(rec[x]!=-1)  return rec[x];
    return rec[x]=(a*f(x-1)+b*f(x-2))%7;
}

void build(int a,int b)
{
    rec[1]=rec[2]=1;
    rec[3]=(a*rec[2]+b*rec[1])%7;
    int m=rec[2],n=rec[3];
    int i;
    for(i=4;;i++)
    {
        rec[i]=(a*rec[i-1]+b*rec[i-2])%7;
        if(rec[i-1]==m&&rec[i]==n)
        {
//            cout<<"the cycle: "<<i-2<<endl;
            cyc = i-3;
            return;
        }
        if(i==N-1)
        {
            printf("%d %d  out of range\n",a,b);
            return;
        }
    }
}

void run()
{
    while(cin>>a>>b>>n)
    {
        if(!a&&!b&&!n) return;
        build(a,b);
        if(cyc==0) {cout<<1<<endl;return;}
        int k = (n-1)%cyc;
        k = (n?k:cyc)+1;
        cout<<rec[k]<<endl;
    }
}

void text()
{
    int ans1,ans2;
    for(a=1;a<=20;a++)
    for(b=1;b<=20;b++)
    for(n=1;n<=20;n++)
    {
        build(a,b);
        if(cyc==0) {cout<<1<<endl;return;}
        int k = (n-1)%cyc;
        k = (n?k:cyc)+1;
        ans1=rec[k];

        memset(rec,-1,sizeof(rec));
        rec[1]=rec[2]=1;
        ans2=f(n);

        if(ans1!=ans2)
        {
            printf("%d\t%d\t%d\t%d\t%d\n",a,b,n,ans1,ans2);
        }
    }
}

int main()
{
    text();
//    run();
//    while(cin>>a>>b)
//    for(a=1;a<=11;a++)
//    for(b=1;b<=10;b++)
//    {
//        cout<<a<<'\t'<<b<<'\t';
//        build(a,b);
//    }

//    while(cin>>a>>b)
//    {
//        memset(rec,-1,sizeof(rec));
//        rec[1]=rec[2]=1;
//        for(n=1;n<=50;n++)
//        {
//            cout<<a<<'\t'<<b<<'\t'<<n<<'\t'<<f(n)<<endl;
//        }
//    }
    return 0;
}
