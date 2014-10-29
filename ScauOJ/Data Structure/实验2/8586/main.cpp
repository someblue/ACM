typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACKINCREMENT 2 // �洢�ռ��������
struct SqStack
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ
Status InitStack(SqStack &S)
{
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
// �벹ȫ����
    S.base = (SElemType*)malloc(STACK_INIT_SIZE);
    if(!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
Status StackEmpty(SqStack S)
{
    if(S.top == S.base ) return 1;
    else return 0;
}
Status Push(SqStack &S,SElemType e)
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
// �벹ȫ����
    if(S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType*)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
// �벹ȫ����
    if(S.top == S.base)  return ERROR;
    e = *(--S.top);
    return OK;
}
void check()
{
    // �������������һ���ַ��������������Ƿ����
    SqStack s;
    SElemType ch[80],*p,e;
    if(InitStack(s)) // ��ʼ��ջ�ɹ�
    {
        //printf("��������ʽ\n");
        gets(ch);
        p=ch;
        while(*p) // û����β
            switch(*p)
            {
            case '(':
            case '[':
                Push(s,*p);p++;
                break; // ��������ջ����p++
            case ')':
            case ']':
                if(!StackEmpty(s)) // ջ����
                {
                    Pop(s,e); // ����ջ��Ԫ��
                    if((*p==')'&&e!='(')||(*p==']'&&e!='['))
                        // ������ջ��Ԫ����*p�����
                    {
                        printf("isn't matched pairs\n");
                        exit(ERROR);
                    }
                    else
                    {
                        p++;
                        break; // ����switch���
                    }
                }
                else // ջ��
                {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                }
            default:
                p++; // �����ַ�������ָ�������
            }
        if(StackEmpty(s)) // �ַ�������ʱջ��
            printf("matching\n");
        else
            printf("lack of right parenthesis\n");
    }
}
int main()
{
    check();
}

/* 8*[3*(35-23)] */
/* 8*3*35-23) */
