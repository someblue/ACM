#include <iostream>
#include <cstdio>
#include <cstring>
#define N 50
typedef long long ll;
using namespace std;
int num[N];

int main()
{
    int i,t,_,ans;
    char s[10];
    memset(num,0,sizeof(num));
    num[0]=1;
    for(i=1;i<31;i++)//num[i]=2^i;
    {
        num[i]=(num[i-1]<<1);
    }
    scanf("%d",&_);
    while(_--)
    {
        ans=1;
        scanf("%d%s",&t,s);
//        printf("%s\n",s);
        for(i=0;i<31;i++)
            if(t==num[i])
                {
                    ans=0;
                    break;
                }
        if(ans)
        {
            if(strcmp(s,"Can")==0)
            {
                printf("Fodder\n");
            }
            else
            {
                printf("Pasture\n");
            }
        }
        else
        {
            if(strcmp(s,"Can")==0)
            {
                printf("Pasture\n");
            }
            else
            {
                printf("Fodder\n");
            }
        }
    }
    return 0;
}
