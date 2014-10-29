#include <iostream>
#include <cstdio>

using namespace std;

int f(int a,int b)
{
    int i,d,n,sum=0;
    for(i=a; i<=b; i++)
    {
        d=0;
        n=i;
        while(n!=0)
        {
            if((n%10)&1)
                d+=n%10;
            else
                d+=2*(n%10);
            n/=10;
        }
        sum+=d%10;
    }
    return sum;
}

int main()
{
    int T,a,b,sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d%d",&a,&b);
//        /*text*/
//        printf("n:D(n)\tF(n)\tn:D(n)\tF(n)\n");
//        /*text*/
        if(b/10==a/10)
            sum=f(a,b);
        else
        {
            sum=(b/10-a/10-1)*45;
            sum+=f(a,(a/10+1)*10-1);
            sum+=f(b/10*10,b);
        }
//            /*text*/
//            printf("%d:%d\t%d",i,d,d%10);
//            if(i&1) printf("\t");
//            else printf("\n");
//            if(!(i%10)) printf("\n");
//            /*text*/
        printf("%d\n",sum);
    }
    return 0;
}
