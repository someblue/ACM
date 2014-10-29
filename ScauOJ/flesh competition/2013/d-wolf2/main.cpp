#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1050

using namespace std;

int flag[N];
char sta[N];

int main()
{
    freopen("case.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int k,x,n,num,nn;
    int t,i;
    int ok;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%s",&n,&x,&k,sta);
        ok=0;nn=n-1;
        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++)
        {
            if(sta[i]=='1')
            {
                num=i;
//                printf("%d:%d",i+1,num);
                while(true)
                {
                    if(num==k-1){ok=1;break;}
                    if(flag[num]==1) break;
                    flag[num]=1;
                    num=nn-(nn/x*(num%x)+(num/x+1)+min(nn%x+1,num%x))+1;
                    //num=n-(n/x*(num%x)+(num/x+1)+min(n%x+1,num%x))+1;
//                    printf("->%d",num);
                }
//                printf("\n");
            }
            if(ok) break;
        }
        if(ok) printf("haha\n");
        else printf("hehe\n");
    }
    return 0;
}
