#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100050

using namespace std;

bool flag[N];
char sta[N];

int main()
{
    int k,x,n,num;
    int t,i;
    bool ok;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%s",&n,&x,&k,sta);
        ok=0;
        memset(flag,0,sizeof(flag));
        for(i=0;sta[i]!='\0';i++)
        {
            if(sta[i]=='1')
            {
                num=i+1;
                printf("%d:%d",i+1,num);
                while(true)
                {
                    if(num==k){ok=1;break;}
                    if(flag[num]) break;
                    flag[num]=1;
                    printf("->%d",num);
                }
                printf("\n");
            }
            if(ok) break;
        }
        if(ok) printf("haha\n");
        else printf("hehe\n");
    }
    return 0;
}
