#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//�û�����255���ڶ�����󴮳�
typedef char SString[MAXSTRLEN+1];	//0�ŵ�Ԫ��Ŵ��ĳ���

void get_next(SString T,int next[])
{
// �㷨4.7
// ��ģʽ��T��next����ֵ����������next
    // �벹ȫ����
    int i,j,len;
    len=strlen(T);
    i=0;j=-1;next[0]=-1;
    while(i<len-1)
    {
        if(j==-1||T[i]==T[j]) next[++i]=++j;
        else j=next[j];
    }
}

void print_next(SString T,int next[])
{
    int i,len;
    len=strlen(T);
    for(i=0;i<len;i++)
        printf("%d ",next[i]);
    printf("\n");
}

int Index_KMP(SString S,SString T,int pos)
{
// �㷨4.6
// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
// KMP�㷨���벹ȫ����
    int next[MAXSTRLEN+1];
    get_next(T,next);
    //print_next(T,next);
    int i,j,slen,tlen;
    slen=strlen(S);
    tlen=strlen(T);
    i=pos;j=0;
    while(i<slen&&j<tlen)
    {
        if(j==-1||S[i]==T[j])
        {
            i++;j++;
        }
        else j=next[j];
        //printf(".");
    }
    if(j>=tlen) return i-tlen;
    return -1;
}
int main()
{
    SString T,S;
    int j,n;
    int pos;
    scanf("%d",&n);    // ָ��n�������ģʽƥ����ַ���
    getchar();
    for(j=0; j<n; j++)
    {
        gets(S);
        gets(T);
        puts(S);
        puts(T);
        pos=Index_KMP(S,T,0);    // pos is 0-base
        printf("%d\n",pos);
    }
}
