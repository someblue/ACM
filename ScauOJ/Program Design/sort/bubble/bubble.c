#include <stdio.h>
void bubble(int a[],int n);

int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    bubble(a,10);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}

void bubble(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
}
