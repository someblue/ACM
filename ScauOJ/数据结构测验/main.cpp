#include <cstdio>
#include <cstring>
#include <cstdlib>
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
// ��������n��Ԫ�صĵ�����
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;q->next=p;q=q->next;
    }
    return OK;
}

int LoadLink_L(LinkList &L)
{
    LinkList p = L->next;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    printf("\n");
    return OK;
}

Status ListInsert_L(LinkList &L, int i, LinkList s) {
  LinkList p;
  p = L;
  int j = 0;
  while (p && j < i-1) {
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;
  s->next = p->next;      //--------------��ʦ��ע�⣬�������Ǿ����޸ĵģ�����-----------------
  p->next = s;
  return OK;
}

int main()
{
    LinkList A,B,C,p,p2;
    int n,bcnt,ccnt;
    scanf("%d",&n);
    CreateLink_L(A,n);
    printf("A��:");LoadLink_L(A);
    CreateLink_L(B,0);
    CreateLink_L(C,0);
    bcnt=ccnt=1;
    p = A->next;
    while(p!=NULL)
    {
        p2 = p;
        p=p->next;
        if(p2->data >= 0) ListInsert_L(B,bcnt++,p2);
        else ListInsert_L(C,ccnt++,p2);
    }
    printf("B��:");LoadLink_L(B);//--------------��ʦ��ע�⣬�������Ǿ����޸ĵģ�����-----------------
    printf("C��:");LoadLink_L(C);//---------����������ͬ�������޸ĺ���ʹ��A��Ľӵ�------------
}
