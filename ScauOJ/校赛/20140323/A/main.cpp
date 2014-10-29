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
    int n,m,i,t,flag1,flag2;
    scanf("%d",&_);
    while(_--)
    {
        memset(num,0,sizeof(num));
        flag1=flag2=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t<0) {flag1=(!flag1);t=-t;}
            num[t]++;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            if(t<0) {flag2=(!flag2);t=-t;}
            num[t]--;
        }
        if(num[2]==0&&num[3]==0&&flag1==flag2)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    run();
    return 0;
}
