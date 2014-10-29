#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n)
{
// 创建含有n个元素的单链表
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // 先建立一个带头结点的单链表
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
        // 请补全代码
        p->data=e;
        p->next=NULL;q->next=p;q=q->next;
    }
    return OK;
}

int LoadLink_L(LinkList &L)
{
// 单链表遍历
    LinkList p = L->next;
    if(p==NULL)printf("The List is empty!"); // 请填空
    else
    {
        //printf("The LinkList is:");
        while(p!=NULL)    // 请填空
        {
            printf("%d ",p->data);
            p=p->next;    // 请填空
        }
    }
    printf("\n");
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

Status LinkMerge_L(LinkList &a, LinkList &b, LinkList &c)
{
    LinkList p,q;
    int ci;
    p=a->next;
    q=b->next;
    ci=1;
    while(p&&q)
    {
        //printf("p:%d q:%d\n",p->data,q->data);
        if((p->data) < (q->data))
        {
            ListInsert_L(c,ci++,p->data);
            p=p->next;
        }
        else
        {
            //printf("1");
            ListInsert_L(c,ci++,q->data);
            q=q->next;
        }
    }
    //LoadLink_L(c);
    if(p)
        while(p)
            {ListInsert_L(c,ci++,p->data);p=p->next;}
    if(q)
        while(q)
            {ListInsert_L(c,ci++,q->data);q=q->next;}
    return OK;
}

int main()
{
    LinkList a,b,c;
    int n;
    scanf("%d",&n);
    CreateLink_L(a,n);
    scanf("%d",&n);
    CreateLink_L(b,n);
    CreateLink_L(c,0);
//    printf("List C:");
//    LoadLink_L(c);
    LinkMerge_L(a,b,c);
    printf("List A:");
    LoadLink_L(a);
    printf("List B:");
    LoadLink_L(b);
    printf("List C:");
    LoadLink_L(c);
    return 0;
}
/*
6
12 24 45 62 84 96
4
15 31 75 86
*/


