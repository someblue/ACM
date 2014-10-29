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
    struct BiTNode *lchild,*rchild;//左右孩子指针
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

Status PrintElement( ElemType e )    // 输出元素e的值
{
    printf("%d ", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
    // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
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
    // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
    if(T)
    {
        InOrderTraverse(T->lchild,PrintElement);
        PrintElement(T->data);
        InOrderTraverse(T->rchild,PrintElement);
    }
    return OK;
} // InOrderTraverse

//非递归算法
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
    // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
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

int main()   //主函数
{
    int n,i;
    ElemType k;
    BiTree T=NULL,temp;
    //input第一行：准备建树的结点个数n
    scanf("%d",&n);
    //input第二行：输入n个整数，用空格分隔
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        InsertBiTNode(T,k);
    }
    //output第一行：二叉树的先序遍历序列
    //output第二行：二叉树的中序遍历序列
    //output第三行：二叉树的后序遍历序列
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //input第三行：输入待查找的关键字
    //input第四行：输入待查找的关键字
    for(i=0;i<2;i++)
    {
        scanf("%d",&k);
        //output第四行：查找结果
        //output第五行：查找结果
        printf("%d\n",FindBiTNode(T,k,temp));
    }
    //input第五行：输入待插入的关键字
    scanf("%d",&k);
    InsertBiTNode(T,k);
    //output第六行~第八行：插入新结点后的二叉树的先、中、序遍历序列
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output第九行：插入新结点后的二叉树的中序遍历序列(非递归算法)
    InOrderTraverse(T,PrintElement);
    printf("\n");
    //output第十行：插入新结点后的二叉树的层次遍历序列
    LevelOrderTraverse(T,PrintElement);
    printf("\n");
    //output第十一行~第十三行：第一次交换各结点的左右子树后的先、中、后序遍历序列
    SwapLeftRightChild(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output第十四行~第十六行：第二次交换各结点的左右子树后的先、中、后序遍历序列
    SwapLeftRightChild(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    //output第十七行：二叉树的深度
    printf("%d\n",CountDegree(T));
    //output第十八行：叶子结点数
    printf("%d\n",CountLeaf(T));
}//main
