#include <stdio.h>
#include <string.h>
int judge(int i,int j,char s[81])
{
	if(s[i]!=s[j]&&i<j)
		return 0;
	else if(i==j-1||i==j)
			return 1;
		else
		{
			i++;j--;
			if(judge(i,j,s))
				return 1;
			else
				return 0;
		}
}

int main()
{
	int i,j,k,l;
	char s[81],s2[80];
	gets(s);
	i=0;j=strlen(s)-1;
	//本身是回文串
	if(judge(i,j,s))
		{printf("Y\n");return 0;}
    //减少一个字符为回文串
	else
	{
	    //减去前面字符为回文串
		for(k=0;k<j;k++)
		{
			for(l=0;l<k;l++)
				s2[l]=s[l];
			for(l=k;l<j;l++)
				s2[l]=s[l+1];
			if(judge(i,j-1,s2))
				{printf("Y\n");return 0;}
		}
		//减去最后一个字符为回文串
		for(l=0;l<j;l++)
            s2[l]=s[l];
        s2[j]=s[j+1];
        if(judge(i,j-1,s2))
				{printf("Y\n");return 0;}
	}
	//其他情况,即不能为回文串
	printf("N\n");
	return 0;
}
