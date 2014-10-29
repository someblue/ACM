#include <queue>
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef int  ElemType;
using namespace std;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status FindBiTNode(BiTree &T,ElemType key,BiTree &last)
{
    last = T;
    while(last)
    {
        if(last->data == key) return OK;
        if(last->data < key)
        {
            if(last->rchild == NULL) return ERROR;
            last = last->rchild;
        }
        if(last->data > key)
        {
            if(last->lchild == NULL) return ERROR;
            last = last->lchild;
        }
    }
    return ERROR;
}

Status InsertBiTNode(BiTree &T,ElemType key)
{
    BiTree last,p;
    p = (BiTree)malloc(sizeof(BiTNode));
    p->lchild = p->rchild = NULL;
    p->data = key;
    if(T==NULL)
    {
        T = p;
    }
    else if(!FindBiTNode(T,key,last))
    {
        if(key < last->data) last->lchild = p;
        else last->rchild = p;
    }
    return OK;
}

Status PrintElement( ElemType e )    // ���Ԫ��e��ֵ
{
    printf("%d ", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // ǰ�����������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
    if(T)
    {
        PrintElement(T->data);
        PreOrderTraverse(T->lchild,PrintElement);
        PreOrderTraverse(T->rchild,PrintElement);
    }
    return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
    if(T)
    {
        InOrderTraverse(T->lchild,PrintElement);
        PrintElement(T->data);
        InOrderTraverse(T->rchild,PrintElement);
    }
    return OK;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
    if(T)
    {
        PostOrderTraverse(T->lchild,PrintElement);
        PostOrderTraverse(T->rchild,PrintElement);
        PrintElement(T->data);
    }
    return OK;
} // PostOrderTraverse

Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
    queue<BiTree> q;
    BiTree t;
    q.push(T);
    while(!q.empty())
    {
        t=q.front();
        printf("%d ",t->data);
        if(t->lchild) q.push(t->lchild);
        if(t->rchild) q.push(t->rchild);
        q.pop();
    }
    return OK;
}

int main()   //������
{
    int n,i;
    ElemType k;
    BiTree T=NULL,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        InsertBiTNode(T,k);
    }
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    for(i=0;i<2;i++)
    {
        scanf("%d",&k);
        printf("%d\n",FindBiTNode(T,k,temp));
    }
    scanf("%d",&k);
    InsertBiTNode(T,k);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    LevelOrderTraverse(T,PrintElement);
    printf("\n");
    //�������
}//main

