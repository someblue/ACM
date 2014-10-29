#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1050

using namespace std;

bool flag[N];
int a1[N],a2[N];

int main()
{
//    freopen("case.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    int x,n,nn,num,cnt;
    int i,j,equ;
//    num=n-(n/x*(num%x)+(num/x+1)+min(n%x+1,num%x))+1;
    for(n=3;n<=1000;n++)
    {
        nn=n-1;
        for(x=1;x<=nn+2;x++)
        {
            cnt=nn;
            for(j=0;j<x;j++)
            {
                i=j;
                while(i<=nn)
                {
                    a1[cnt--]=i;
                    i+=x;
                }
            }
            cnt=0;
            for(i=0;i<=nn;i++)
            {
                num=i;
                num=nn-(nn/x*(num%x)+(num/x+1)+min(nn%x+1,num%x))+1;
                a2[num]=i;
            }
            equ=1;
            for(i=0;i<=nn;i++)
            {
                if(a1[i]!=a2[i])
                {
                    equ=0;break;
                }
            }
            if(!equ)
            {
                    printf("n:%d,x:%d\na1:",n,x);
                    for(j=0;j<=nn;j++)
                        printf("%d ",a1[j]);
                    printf("\na2:");
                    for(j=0;j<=nn;j++)
                        printf("%d ",a2[j]);
                    printf("\n");
            }
        }
    }
    return 0;
}
