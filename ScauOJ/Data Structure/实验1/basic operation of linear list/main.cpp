#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
// �벹ȫ����
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ERROR;
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",*(L.elem+i));  // �����
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// �㷨2.4����˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
// i�ĺϷ�ֵΪ1��i��L.length +1
// �벹ȫ����
    if(i<1||i>L.length+1) return ERROR;
    if(L.length>=L.listsize)
    {
        ElemType *newbase;
        newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(newbase==NULL) return ERROR;
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    ElemType *q,*p;
    q=(L.elem+i-1);
    for(p=(L.elem+L.length-1);p>=q;p--)
        *(p+1)=*p;
    *q=e;
    L.length++;
    return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// �㷨2.5,��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
// i�ĺϷ�ֵΪ1��i��L.length
// �벹ȫ����
    if(i<1||i>L.length) return ERROR;
    ElemType *p,*q;
    q=(L.elem+i-1);
    e=*q;
    p=(L.elem+L.length-1);
    for(q++;q<=p;q++)
        *(q-1)=*q;
    L.length--;
    return OK;
}

int main()
{
    //freopen("case.txt","r",stdin);
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // �ж�˳����Ƿ񴴽��ɹ�
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(ListInsert_Sq(T,i,x)==ERROR) printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(ListDelete_Sq(T,i,e)==ERROR) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}

/*
���ݲ˵�������
1������1����ʾҪʵ�ֲ��������������Ҫ��������λ�ú�Ԫ�أ��ÿո�ֿ�
2������2����ʾҪʵ��ɾ��������������Ҫ����ɾ����λ��
3������3����ʾҪ���˳��������Ԫ��
4������0����ʾ�������
*/
