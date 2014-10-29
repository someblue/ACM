#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int flag=2;

int is_int(double k)
{
    return (floor(k+0.5)==k);
}

void triangle(int a,int n)
{
    if(flag) flag--;
    else printf("\n");
    int H,max;
    double L;
    max=(int)((a*a+1)/2);
    for(H=max;H>a;H--)
    {
        L=sqrt(H*H-a*a);
        if(is_int(L))
        {
            if(flag) flag--;
            else printf("\n");
            printf("%d,%.0f",H,L);
        }
    }
    for(H=a-1;;H--)
    {
        L=sqrt(a*a-H*H);
        if(L>H) break;
        if(is_int(L))
        {
            if(flag) flag=0;
            else printf("\n");
            printf("%d,%.0f",H,L);
        }
    }
}

int main()
{
    //freopen("case.txt","r",stdin);
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        if(a==1)
        {
            printf("\n");
            continue;
        }
        triangle(a,n);
    }
    //printf("--EOF--");
    return 0;
}
