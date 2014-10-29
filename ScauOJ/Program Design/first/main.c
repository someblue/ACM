#include<stdio.h>
int main()
{int m,n,i;
float s,sum=0;
scanf("%d\n%d",&m,&n);
for(i=m;i<=n;i++){
    s=i*i+1.0/i;sum=sum+s;
}
printf("%f",sum);

}
