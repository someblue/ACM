#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode,*LinkList;

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
        printf("The LinkList is:");
        while(p!=NULL)    // �����
        {
            printf("%d ",p->data);
            p=p->next;    // �����
        }
    }
    printf("\n");
    return OK;
}

void CreateList_L(LinkList &L,int n)
{
    LinkList *q,*p;
    int i;
    L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
    q=L;
    for(i=n;i>0;--i)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
}

int LinkInsert_L(LinkList &L,int i,ElemType e)
{
// �㷨2.9
// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
// �벹ȫ����
    LinkList p,s;
    int j;
    p=L;j=0;
    while(p&&j<i-1){p=p->next;j++;}
    if(!p) return ERROR;
    s=(LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e)
{
// �㷨2.10
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
// �벹ȫ����
    LinkList p,q;
    int j;
    p=L;j=0;
    while(p->next&&j<i-1){p=p->next;j++;}
    if(!(p->next)||j>i-1) return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return OK;
}

int main()
{
    LinkList T;
    int a,n,i;
    ElemType x, e;
    printf("Please input the init size of the linklist:\n");
    scanf("%d",&n);
    printf("Please input the %d element of the linklist:\n", n);
    if(CreateLink_L(T,n)==OK)     // �ж������Ƿ񴴽��ɹ��������
    {
        printf("A Link List Has Created.\n");
        LoadLink_L(T);
    }
    while(1)
    {
        printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            scanf("%d%d",&i,&x);
            if(LinkInsert_L(T,i,x)==ERROR) printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
            else printf("The Element %d is Successfully Inserted!\n", x);
            break;
        case 2:
            scanf("%d",&i);
            if(LinkDelete_L(T,i,e)==ERROR) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
            else printf("The Element %d is Successfully Deleted!\n", e);
            break;
        case 3:
            LoadLink_L(T);
            break;
        case 0:
            return 1;
        }
    }
}
