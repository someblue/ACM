#include <stdio.h>
#include <iostream>

long long H(int n)
{
	long long res=0;
	int i,num[100000],temp,counter,equ=0;
	for(i=1;;i++)
	{
		temp=n/i;
		if(i==temp)equ=1;
		if(i>temp)
		{
			counter=i;
			num[i]=temp;
			break;
		}
		else
			num[i]=temp;
	}
	for(i=1;i<counter;i++)
	{
		res += num[i];
		res += i*(num[i]-num[i+1]);
	}
	if(equ)res -= (counter-1);
	return res;
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		printf("%I64d\n",H(n));
	}
	system("pause");
} 
