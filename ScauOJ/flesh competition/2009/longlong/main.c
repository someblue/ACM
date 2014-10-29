#include <stdio.h>
#include <stdlib.h>
void f()
{
    long long res = 0;
    int i,n;
    scanf("%d",&n);
    for(i = 1; i <= n; i=i+1 ){
        res = (res + n/i);
        printf("%d,%d  ",i,n/i);
        if(i%10==0)printf("\n");
    }
    printf("res:%I64d\n",res);
}
int main()
{
    while(1) f();
    return 0;
}
