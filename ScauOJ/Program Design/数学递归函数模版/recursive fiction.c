#include <stdio.h>

int main(void)
{
    int n,i;
    double num[100];
    scanf("%d",&n);
    num[0]=1;//������ֵ
    printf("1:%lf\n",num[0]);
    for(i=1;i<n;i++)
    {
        num[i]=(num[i-1]+9/num[i-1])/2;//�ݹ鹫ʽ
        printf("%d:%.12lf\n",i+1,num[i]);
    }
    return 0;
}
