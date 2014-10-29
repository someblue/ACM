#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 1000

struct {
    int power;
    int mod;
} num[MAXN];

int main()
{
    //freopen("case.in","r",stdin);

    int k,power=0,mod=1,flag=0;
    int i,j;
    scanf("%d",&k);
    while(pow(k,++power)<1000);
    mod=(int)(pow(k,power)+0.5)%MAXN;
    for(i=0;i<MAXN+1;power++,i++)
    {
        if(i!=0)
            mod=(mod%MAXN)*(k%MAXN)%MAXN;
        num[i].power=power;
        num[i].mod=mod;
        for(j=0;j<i;j++)
            if(num[j].mod==num[i].mod)
            {
                //printf("m:%d,n:%d\n",num[i].power,num[j].power);
                printf("%d\n",num[i].power+num[j].power);
                flag=1;
                break;
            }
        if(flag) break;
    }
    return 0;
}
