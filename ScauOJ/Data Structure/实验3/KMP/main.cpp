#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//用户可在255以内定义最大串长
typedef char SString[MAXSTRLEN+1];	//0号单元存放串的长度

void get_next(SString T,int next[])
{
// 算法4.7
// 求模式串T的next函数值并存入数组next
    // 请补全代码
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
// 算法4.6
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
// KMP算法。请补全代码
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
    scanf("%d",&n);    // 指定n对需进行模式匹配的字符串
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
