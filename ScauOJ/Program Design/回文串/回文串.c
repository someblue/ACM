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
	//�����ǻ��Ĵ�
	if(judge(i,j,s))
		{printf("Y\n");return 0;}
    //����һ���ַ�Ϊ���Ĵ�
	else
	{
	    //��ȥǰ���ַ�Ϊ���Ĵ�
		for(k=0;k<j;k++)
		{
			for(l=0;l<k;l++)
				s2[l]=s[l];
			for(l=k;l<j;l++)
				s2[l]=s[l+1];
			if(judge(i,j-1,s2))
				{printf("Y\n");return 0;}
		}
		//��ȥ���һ���ַ�Ϊ���Ĵ�
		for(l=0;l<j;l++)
            s2[l]=s[l];
        s2[j]=s[j+1];
        if(judge(i,j-1,s2))
				{printf("Y\n");return 0;}
	}
	//�������,������Ϊ���Ĵ�
	printf("N\n");
	return 0;
}
