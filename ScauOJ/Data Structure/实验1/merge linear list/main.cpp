#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����
	else
		for(i=0;i<L.length;i++) printf("%d ",*(L.elem+i));  // �����
	printf("\n");
	return OK;
}

Status InitList_Sq(SqList &L)
{
    // �㷨2.3
    // ����һ���յ����Ա�L��
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem) return OK;        // �洢����ʧ��
    L.length = 0;                  // �ձ���Ϊ0
    L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // �㷨2.4
    // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
    // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
    ElemType *p;
    if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
    if (L.length >= L.listsize)     // ��ǰ�洢�ռ���������������
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof (ElemType));
        if (!newbase) return ERROR;   // �洢����ʧ��
        L.elem = newbase;             // �»�ַ
        L.listsize += LISTINCREMENT;  // ���Ӵ洢����
    }
    ElemType *q = &(L.elem[i-1]);   // qΪ����λ��
    for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
    // ����λ�ü�֮���Ԫ������
    *q = e;       // ����e
    ++L.length;   // ����1
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    // �㷨2.5
    // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
    // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
    ElemType *p, *q;
    if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
    p = &(L.elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem+L.length-1;                // ��βԪ�ص�λ��
    for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
    --L.length;                           // ����1
    return OK;
} // ListDelete_Sq

Status mergeList(SqList &la,SqList &lb,SqList &lc)
{
    int p,q,lena,lenb;
    lena=la.length;lenb=lb.length;
    p=q=0;
    while(p<lena&&q<lenb)
    {
        if(la.elem[p]<=lb.elem[q])
            ListInsert_Sq(lc,lc.length+1,la.elem[p++]);
        else
            ListInsert_Sq(lc,lc.length+1,lb.elem[q++]);
    }
    while(p<lena)
        ListInsert_Sq(lc,lc.length+1,la.elem[p++]);
    while(q<lenb)
        ListInsert_Sq(lc,lc.length+1,lb.elem[q++]);
    return OK;
}

int main()
{
    freopen("case.txt","r",stdin);
    int numa,numb,pst,t;
    SqList Ta,Tb,Tc;
    InitList_Sq(Ta);
    InitList_Sq(Tb);
    InitList_Sq(Tc);
    scanf("%d",&numa);
    for(pst=1;pst<=numa;pst++)
    {
        scanf("%d",&t);
        ListInsert_Sq(Ta,pst,t);
    }
    scanf("%d",&numb);
    for(pst=1;pst<=numb;pst++)
    {
        scanf("%d",&t);
        ListInsert_Sq(Tb,pst,t);
    }
    mergeList(Ta,Tb,Tc);
    printf("List A:");Load_Sq(Ta);
    printf("List B:");Load_Sq(Tb);
    printf("List C:");Load_Sq(Tc);
    return 0;
}

/*
��һ�У�˳���A��Ԫ�ظ���
�ڶ��У�˳���A�ĸ�Ԫ�أ��ǵݼ������ÿո�ֿ�
�����У�˳���B��Ԫ�ظ���
�����У�˳���B�ĸ�Ԫ�أ��ǵݼ������ÿո�ֿ�
*/
