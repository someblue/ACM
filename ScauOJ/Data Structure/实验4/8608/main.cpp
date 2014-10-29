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

//�ǵݹ��㷨
//Status InOrderTraverse2(BiTree t,Status(* Visit)(ElemType e))
//{
//    BiTree p;
//    SqStack S;
//    InitStack(S);
//    p=t;
//    while(p||!StackEmpty(S))
//    {
//        if(p)
//        {
//            Push(S,p);
//            p=p->lchild;
//        }
//        else
//        {
//            Pop(S,p);
//            printf("%d ",p->data.key);
//            p=p->rchild;
//        }
//    }
//    return OK;
//}


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

Status SwapLeftRightChild(BiTree &T)
{
    if(!T) return OK;
    swap(T->lchild,T->rchild);
    SwapLeftRightChild(T->lchild);
    SwapLeftRightChild(T->rchild);
    return OK;
}

int CountDegree(BiTree &T)
{
    if(!T) return 0;
    return max(CountDegree(T->lchild),CountDegree(T->rchild))+1;
}

int CountLeaf(BiTree &T)
{
    if(!T->lchild && !T->rchild) return 1;
    int ans=0;
    if(T->lchild) ans+=CountLeaf(T->lchild);
    if(T->rchild) ans+=CountLeaf(T->rchild);
    return ans;
}

int main()   //������
{
    int n,i;
    ElemType k;
    BiTree T=NULL,temp;
    //input��һ�У�׼�������Ľ�����n
    scanf("%d",&n);
    //input�ڶ��У�����n���������ÿո�ָ�
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        InsertBiTNode(T,k);
    }
    //output��һ�У��������������������
    //output�ڶ��У��������������������
    //output�����У��������ĺ����������
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //input�����У���������ҵĹؼ���
    //input�����У���������ҵĹؼ���
    for(i=0;i<2;i++)
    {
        scanf("%d",&k);
        //output�����У����ҽ��
        //output�����У����ҽ��
        printf("%d\n",FindBiTNode(T,k,temp));
    }
    //input�����У����������Ĺؼ���
    scanf("%d",&k);
    InsertBiTNode(T,k);
    //output������~�ڰ��У������½���Ķ��������ȡ��С����������
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output�ھ��У������½���Ķ������������������(�ǵݹ��㷨)
    InOrderTraverse(T,PrintElement);
    printf("\n");
    //output��ʮ�У������½���Ķ������Ĳ�α�������
    LevelOrderTraverse(T,PrintElement);
    printf("\n");
    //output��ʮһ��~��ʮ���У���һ�ν���������������������ȡ��С������������
    SwapLeftRightChild(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output��ʮ����~��ʮ���У��ڶ��ν���������������������ȡ��С������������
    SwapLeftRightChild(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output��ʮ���У������������
    printf("%d\n",CountDegree(T));
    //output��ʮ���У�Ҷ�ӽ����
    printf("%d\n",CountLeaf(T));
}//main
