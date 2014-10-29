#include <stdio.h>

int main()
{
    int prime[100000],n,i,j,counter,scope,flag;
    prime[0]=2;prime[1]=3;
    counter=2;
    printf("input the scope:");
    scanf("%d",&scope);
    printf("2\n3\n");
    for(i=2;;i++)
    {
        //------------------6n-1------------------
        flag=1;
        n=6*(i-1)-1;
        if(n>scope)break;
        for(j=0;j<counter;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            printf("%d\n",n);
            counter++;
        }
        //------------------6n+1------------------
        flag=1;
        n=6*(i-1)+1;
        if(n>scope)break;
        for(j=0;j<counter;j++)
            if(n%prime[j]==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            prime[counter]=n;
            printf("%d\n",n);
            counter++;
        }
    }
    return 0;
}
