#include<stdio.h>
#include<math.h>
int main(void)
{
	int i,j,scope=100000;
	printf("input the scope:");
	scanf("%d",&scope);
	printf("2\n3\n");
	for(i=5;i<=scope;i++)
    {
        if(i%2==0)continue;
        for(j=3;j<=sqrt(i);j+=2)
            if(i%j==0)break;
        if(j>sqrt(i));
            printf("%d\n",i);
    }
	return 0;
}
