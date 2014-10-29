#include <stdio.h>
int main()
{
    int a[3][4];
    int i,j;
    int max[3]={-9999},maxi[3];
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>max[i])
            {
                max[i]=a[i][j];
                maxi[i]=j;
            }
        }
    j=1;
    if(a[0][maxi[0]]<a[1][maxi[0]]&&a[0][maxi[0]]<a[2][maxi[0]])
    {
        printf("%d",a[0][maxi[0]]);
        j=0;
    }
    if(a[1][maxi[1]]<a[0][maxi[1]]&&a[1][maxi[1]]<a[2][maxi[1]])
    {
        printf("%d",a[1][maxi[1]]);
        j=0;
    }
    if(a[2][maxi[2]]<a[0][maxi[2]]&&a[2][maxi[2]]<a[1][maxi[2]])
    {
        printf("%d",a[2][maxi[2]]);
        j=0;
    }
    if(j)
        printf("NO\n");
    return 0;
}
