#include <iostream>
#include <cstdio>
#include <cstring>
#define N 5
int num[N];
typedef long long ll;
using namespace std;
void run()
{
    int _;
    int n,m,i,t,flag1,flag2,zero1,zero2,ok;
    scanf("%d",&_);
    while(_--)
    {
        memset(num,0,sizeof(num));
        flag1=flag2=0;
        zero1=zero2=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t<0) {flag1=(!flag1);t=-t;}
            if(t==0||zero1==1) zero1=1;
            num[t]++;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            if(t<0) {flag2=(!flag2);t=-t;}
            if(t==0||zero2==1) zero2=1;
            num[t]--;
        }
        if(zero1 && zero2) ok=1;
        else if(zero1||zero2 ) ok=0;
        else if(num[2]==0&&num[3]==0) ok=1;
        else ok=0;
        printf("%s\n",ok?"Yes":"No");
    }
}

int main()
{
    run();
    return 0;
}
