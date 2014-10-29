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
// ��������n��Ԫ�صĵ�����
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));  // �����½��
        // �벹ȫ����
        p->data=e;
        p->next=NULL;q->next=p;q=q->next;
    }
    return OK;
}

int LoadLink_L(LinkList &L)
{
// ���������
    LinkList p = L->next;
    if(p==NULL)printf("The List is empty!"); // �����
    else
    {
        //printf("The LinkList is:");
        while(p!=NULL)    // �����
        {
            printf("%d ",p->data);
            p=p->next;    // �����
        }
    }
    printf("\n");
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {  // �㷨2.9
  // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // Ѱ�ҵ�i-1�����
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // iС��1���ߴ��ڱ�
  s = (LinkList)malloc(sizeof(LNode));  // �����½��
  s->data = e;  s->next = p->next;      // ����L��
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // �㷨2.10
  // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // Ѱ�ҵ�i����㣬����pָ����ǰ��
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // ɾ��λ�ò�����
  q = p->next;
  p->next = q->next;           // ɾ�����ͷŽ��
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


