#include <stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    //the high half;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(j=i-1;j>=1;j--)
            printf("%d",j);
        printf("\n");
    }
    //the middle line
    for(i=1;i<=n;i++)
        printf("%d",i);
    for(i=n-1;i>=1;i--)
        printf("%d",i);
    printf("\n");
    //the upper half;
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(j=i-1;j>=1;j--)
            printf("%d",j);
        printf("\n");
    }
    return 0;
}
