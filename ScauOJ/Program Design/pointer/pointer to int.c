#include <stdio.h>
int main()
{
    int a=10;
    int *ptoa;
    int **ptopa;
    ptoa=&a;ptopa=&ptoa;
    printf("&ptopa:%d \n",&ptopa);
    printf("&ptoa:%d,ptopa:%d \n",&ptoa,ptopa);
    printf("&a:%d,ptoa:%d,*ptopa:%d \n",&a,ptoa,*ptopa);
    printf("a:%d,*ptoa:%d,**ptopa:%d \n",a,*ptoa,**ptopa);
    return 0;
}
