#include <stdio.h>
int div(int m,int n);
int main()
{
    int m,n,divisor,t;
    scanf("%d,%d",&m,&n);
    if(m<n)
    {
        t=n;n=m;m=t;
    }
    divisor=div(m,n);
    printf("%d\n",divisor);
    return 0;
}
int div(int m,int n)
{
    if(n==0) return m;
    else{int t;
        t=m%n;
        div(n,t);}
}
