#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int f(int i)
{
    if(i<3) return i;
    if(i%3==0)
        return f(i/3)*2;
    if(i%3==1)
        return f((i-1)/3)+1;
    if(i%3==2)
        return f((i-2)/3)+2;
}


int main()
{
    //freopen("case.in","r",stdin);
    int i;
    scanf("%d",&i);
    printf("%d\n",f(i));
    return 0;
}
