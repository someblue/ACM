#include<malloc.h>
#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������
#define SLEN 10000

char s[SLEN];

typedef int SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
     SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
     SElemType *top; // ջ��ָ��
     int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
     e=*--S.top;
	 return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
    e=*(S.top-1);
	return OK;
}

SElemType GetTop(SqStack S)
{
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
    return *(S.top-1);
}

int StackLength(SqStack S)
{
// ����ջS��Ԫ�ظ���
	int i;
    i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
	SElemType *p = (SElemType *)malloc(sizeof(SElemType));
	p = S.top;
	if(S.top==S.base)printf("The Stack is Empty!");
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)
		{
			printf("%d ", *p);
			p--;
		}
	}
	printf("\n");
	return OK;
}

bool isnum(int c){return c>='0'&&c<='9';}

int getnum(int &i)
{
    //printf("getnum\n");
    int num=0;
    while(isnum(s[i++])) num = num*10 + s[i-1]-'0';
    i-=2;
    return num;
}

int Operate(int a,char oper,int b)
{
    //printf("Operate %d%c%d\n",a,oper,b);
    switch(oper)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    exit(-1);
}

char Precede(char a,char b)
{
    //printf("Precede\n");
    switch(a)
    {
    case '+':case '-':
        if(b=='+'||b=='-'||b==')'||b=='=') return '>';
        else return '<';
        break;
    case '*':case '/':
        if(b=='(') return '<';
        else return '>';
        break;
    case '(':
        if(b==')') return '=';
        else if(b=='=') exit(1);
        else return '<';
        break;
    case ')':
        if(b=='(') exit(2);
        else return '>';
        break;
    case '=':
        if(b=='=') return '=';
        else if(b==')') exit(3);
        else return '<';
        break;
    }
    exit(-2);
    return ERROR;
}

int CaculExp()
{
    SqStack optr,opnd;
    InitStack(optr);
    InitStack(opnd);
    Push(optr,'=');
    scanf("%s",s);
    int i,len=strlen(s),a,b,temp;
    char c,theta;
    for(i=0;i<len;i++)
    {
        //printf("forCycle i=%d\n",i);

        c=s[i];
        if(isnum(c))
        {
            //printf("before getnum  i = %d\n",i);
            Push(opnd,getnum(i));
            //printf("after getnum i = %d\n",i);
            //printf("%c ---- getnum=%d\n",c,GetTop(opnd));
            continue;
        }
        //printf("Precede= '%c'\n",Precede(GetTop(optr),c));
        switch(Precede(GetTop(optr),c))
        {
        case '<':
            Push(optr,c);
            break;
        case '>':
            Pop(optr,temp); theta = (char)temp;
            Pop(opnd,b);Pop(opnd,a);
            Push(opnd,Operate(a,theta,b));
            //Push(optr,c);
            i--;
            break;
        case '=':
            Pop(optr,temp);
            break;
        }
    }
    return GetTop(opnd);
}
/*
3*(9-7)=
*/

int main()
{
    printf("%d\n",CaculExp());
    return 0;
}
